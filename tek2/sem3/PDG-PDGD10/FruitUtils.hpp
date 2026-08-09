/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** FruitUtils
*/

#ifndef FRUITUTILS_HPP_
    #define FRUITUTILS_HPP_

#include "FruitBox.hpp"

class FruitUtils {
    public:
        FruitUtils();
        ~FruitUtils();
        static void sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry);
        static FruitBox **pack(IFruit **fruits, unsigned int nbBox);
        static IFruit **unpack(FruitBox **boxes);

    protected:
    private:
};

#endif /* !FRUITUTILS_HPP_ */
