/*
** EPITECH PROJECT, 2024
** R-Type ECS
** File description:
** Registry
*/

#ifndef REGISTRY_H
#define REGISTRY_H

#include <unordered_map>
#include <typeindex>
#include <any>
#include <functional>
#include <vector>
#include <stdexcept>
#include "SparseArray.hpp"


class Registry {
public:
    using Entity = std::size_t;

    Entity spawn_entity() {
        if (!deadEntities.empty()) {
            Entity id = deadEntities.back();
            deadEntities.pop_back();
            return id;
        }
        return nextEntity++;
    }

    Entity entity_from_index(std::size_t idx) {
        return static_cast<Entity>(idx);
    }

    void kill_entity(Entity const& e) {
        for (auto& func : eraseFunctions) {
            func(*this, e);
        }
        deadEntities.push_back(e);
    }

    template<typename Component>
    sparse_array<Component>& register_component() {
        auto typeIndex = std::type_index(typeid(Component));
        if (_componentArrays.find(typeIndex) == _componentArrays.end()) {
            _componentArrays[typeIndex] = sparse_array<Component>();
            eraseFunctions.push_back([](Registry& reg, Entity const& e) {
                reg.get_components<Component>().erase(e);
            });
        }
        return std::any_cast<sparse_array<Component>&>(_componentArrays[typeIndex]);
    }

    template <class Component>
    sparse_array<Component>& get_components() {
        auto typeIndex = std::type_index(typeid(Component));
        auto it = _componentArrays.find(typeIndex);
        if (it == _componentArrays.end()) {
            throw std::out_of_range("get_components(): Component array not found for type " + std::string(typeid(Component).name()));
        }
        try {
            return std::any_cast<sparse_array<Component>&>(it->second);
        } catch (const std::bad_any_cast&) {
            throw std::runtime_error("get_components(): Type mismatch in std::any_cast for " + std::string(typeid(Component).name()));
        }
    }


    template <class Component>
    const sparse_array<Component>& get_components() const {
        auto typeIndex = std::type_index(typeid(Component));
        if (_componentArrays.find(typeIndex) == _componentArrays.end()) {
            throw std::out_of_range("get_components(): Component array not found");
        }
        return std::any_cast<const sparse_array<Component>&>(_componentArrays.at(typeIndex));
    }

    template <typename Component>
    typename sparse_array<Component>::reference_type add_component(Entity const& to, Component&& c) {
        if (!entity_exists(to)) {
            throw std::out_of_range("Entity does not exist");
        }
        return get_components<Component>().insert_at(to, std::forward<Component>(c));
    }

    template <typename Component, typename... Params>
    typename sparse_array<Component>::reference_type emplace_component(Entity const& to, Params&&... p) {
        if (!entity_exists(to)) {
            throw std::out_of_range("Entity does not exist");
        }
        return get_components<Component>().emplace_at(to, std::forward<Params>(p)...);
    }

    template <typename Component>
    void remove_component(Entity const& from) {
        get_components<Component>().erase(from);
    }

    template <class... Components, typename Function>
    void add_system(Function&& f) {
        systems.emplace_back([this, f = std::forward<Function>(f)]() {
            f(*this, get_components<Components>()...);
        });
    }

    void run_systems() {
        for (auto& system : systems) {
            system();
        }
    }

    template <typename Component>
    bool has_component(Entity const& entity) const {
        if (!entity_exists(entity)) {
            return false;
        }
        auto typeIndex = std::type_index(typeid(Component));
        if (_componentArrays.find(typeIndex) == _componentArrays.end()) {
            return false;
        }
        const auto& array = std::any_cast<const sparse_array<Component>&>(_componentArrays.at(typeIndex));
        return array.contains(entity);
    }

    bool entity_exists(Entity const& entity) const {
        return entity < nextEntity && std::find(deadEntities.begin(), deadEntities.end(), entity) == deadEntities.end();
    }

private:
    Entity nextEntity = 0;
    std::vector<Entity> deadEntities;
    std::unordered_map<std::type_index, std::any> _componentArrays;
    std::vector<std::function<void(Registry&, Entity const&)>> eraseFunctions;
    std::vector<std::function<void()>> systems;
};

#endif // REGISTRY_H
