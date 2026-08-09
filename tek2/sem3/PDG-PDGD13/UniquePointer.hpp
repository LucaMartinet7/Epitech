/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD13-luca.martinet
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
    #define UNIQUEPOINTER_HPP_

template<typename T>
class UniquePointer {
    public:
        UniquePointer(T *ptr = nullptr) : ptr(ptr) {};
        ~UniquePointer()
        {
            delete this->ptr;
        };
        UniquePointer<T> &operator=(T *other)
        {
            delete this->ptr;
            this->ptr = other;
            return *this;
        };
        T *operator->() const
        {
            return this->ptr;
        };
        T *get() const
        {
            return this->ptr;
        };
        void reset(T *ptr = nullptr)
        {
            delete this->ptr;
            this->ptr = ptr;
        };

    private:
        T *ptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
