/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** List
*/

#include "List.hpp"

List::List() {}

List::~List()
{
    for (IObject *obj: this->list)
        delete obj;
}

bool List::empty() const
{
    return this->list.empty();
}

std::size_t List::size() const
{
    return this->list.size();
}

IObject *&List::front()
{
    if (this->list.empty())
        throw InvalidOperationException();
    return this->list.front();
}

IObject *List::front() const
{
    if (this->list.empty())
        throw InvalidOperationException();
    return this->list.front();
}

IObject *&List::back()
{
    if (this->list.empty())
        throw InvalidOperationException();
    return this->list.back();
}

IObject *List::back() const
{
    if (this->list.empty())
        throw InvalidOperationException();
    return this->list.back();
}

void List::pushBack(IObject *Obj)
{
    this->list.push_back(Obj);
}

void List::pushFront(IObject *Obj)
{
    this->list.insert(this->list.begin(), Obj);
}

void List::popFront()
{
    if (this->list.empty())
        throw InvalidOperationException();
    IObject *tmp = this->list.front();
    delete tmp;
    this->list.erase(this->list.begin());
}

void List::popBack()
{
    if (this->list.empty())
        throw InvalidOperationException();
    IObject *tmp = this->list.back();
    delete tmp;
    this->list.pop_back();
}

void List::clear()
{
    for (auto &i : this->list)
        delete i;
    this->list.clear();
}

void List::forEach(void(*function)(IObject *Obj))
{
    for (auto &i : this->list)
        function(i);
}
