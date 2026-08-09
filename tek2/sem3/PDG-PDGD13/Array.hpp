/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD13-luca.martinet
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <vector>
#include <functional>

template<typename Type, size_t Size>
class Array {
    public:
        std::vector<Type> array = std::vector<Type>(Size);

        class OutOfRangeException : public std::exception {
            public:
                const char *what() const noexcept override
                {
                    return "Index out of range";
                };
        };
        std::size_t size() const
        {
            return Size;
        };
        void forEach(const std::function<void(const Type&)> &task) const
        {
            for (auto &elem : this->array)
                task(elem);
        };
        template<typename U>
        Array<U, Size> convert(const std::function<U(const Type&)> &converter) const
        {
            Array<U, Size> newArray;
            for (size_t i = 0; i < Size; i++)
                newArray[i] = converter(this->array[i]);
            return newArray;
        };
        Type &operator[](std::size_t index)
        {
            if (index >= Size)
                throw OutOfRangeException();
            return this->array[index];
        };
        Type operator[](std::size_t index) const
        {
            if (index >= Size)
                throw OutOfRangeException();
            return this->array[index];
        };
};

std::ostream& operator<<(std::ostream &os, const Array<int, 3> &array)
{
    os << "[";
    for (size_t i = 0; i < array.size(); i++) {
        os << array[i];
        if (i < array.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

#endif /* !ARRAY_HPP_ */
