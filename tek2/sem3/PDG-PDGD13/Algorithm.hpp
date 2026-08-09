/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD13-luca.martinet
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
    #define ALGORITHM_HPP_

template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T a, T b)
{
    if (a < b)
        return a;
    else if (b < a)
        return b;
    else
        return a;
}

template<typename T>
T max(T a, T b)
{
    if (a > b)
        return a;
    else if (b > a)
        return b;
    else
        return a;
}

template<typename T>
T clamp(T value, T min, T max)
{
    if (value < min)
        return min;
    else if (value > max)
        return max;
    else
        return value;
}

#endif /* !ALGORITHM_HPP_ */
