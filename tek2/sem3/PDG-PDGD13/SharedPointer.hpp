/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD13-luca.martinet
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
    #define SHAREDPOINTER_HPP_

#include <iostream>
#include <unordered_map>

template<typename T>
static std::unordered_map<T*, std::size_t> map;

template<typename T>
class SharedPointer {
    public:
        SharedPointer(T *ptr = nullptr)
        {
            if (ptr != nullptr)
                map<T>[ptr]++;
            this->ptr = ptr;
        };
        ~SharedPointer()
        {
            reset();
        };
        SharedPointer(const SharedPointer<T> &other)
        {
            this->ptr = other.ptr;
            map<T>[this->ptr]++;
        };
        SharedPointer<T> &operator=(const SharedPointer<T> &other)
        {
            reset();
            this->ptr = other.ptr;
            map<T>[this->ptr]++;
            return *this;
        };
        SharedPointer<T> &operator=(T *other)
        {
            reset();
            this->ptr = other;
            map<T>[this->ptr]++;
            return *this;
        };
        T &operator*() const
        {
            return *this->ptr;
        };
        T *operator->() const
        {
            return this->ptr;
        };
        void reset(T *ptr = nullptr)
        {
            if (this->ptr != nullptr) {
                map<T>[this->ptr]--;
                if (map<T>[this->ptr] == 0) {
                    delete this->ptr;
                    map<T>.erase(this->ptr);
                }
            }
            this->ptr = ptr;
        };
        T *get() const
        {
            return this->ptr;
        };

    private:
        T *ptr = nullptr;
};

#endif /* !SHAREDPOINTER_HPP_ */
