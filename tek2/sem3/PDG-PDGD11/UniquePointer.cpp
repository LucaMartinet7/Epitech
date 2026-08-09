/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** UniquePointer
*/

#include "UniquePointer.hpp"

UniquePointer::UniquePointer() : ptr(nullptr) {}

UniquePointer::UniquePointer(IObject *Obj) : ptr(Obj) {}

UniquePointer::~UniquePointer()
{
    delete ptr;
}

void UniquePointer::reset(IObject *Obj)
{
    if (this->ptr)
        delete this->ptr;
    this->ptr = Obj;
}

void UniquePointer::swap(UniquePointer &Obj)
{
    if (this->ptr == Obj.ptr)
        return;
    IObject *tmp = this->ptr;
    this->ptr = Obj.ptr;
    Obj.ptr = tmp;
}

UniquePointer &UniquePointer::operator=(IObject *Obj)
{
    if (this->ptr)
        delete this->ptr;
    this->ptr = Obj;
    return *this;
}

IObject *UniquePointer::operator->()
{
    return this->ptr;
}

IObject &UniquePointer::operator*()
{
    return *this->ptr;
}
