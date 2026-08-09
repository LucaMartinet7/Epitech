/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
    #define UNIQUEPOINTER_HPP_

#include "IObject.hpp"

class UniquePointer {
    public:
        UniquePointer();
        UniquePointer(IObject *Obj);
        ~UniquePointer();
        void reset(IObject *Obj = nullptr);
        void swap(UniquePointer &Obj);

        UniquePointer &operator=(IObject *Obj);
        IObject *operator->();
        IObject &operator*();

    protected:
    private:
        IObject *ptr = nullptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
