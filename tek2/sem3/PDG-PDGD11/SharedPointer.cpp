/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** SharedPointer
*/

#include "SharedPointer.hpp"
#include <memory>


SharedPointer::SharedPointer() {}

SharedPointer::SharedPointer(const SharedPointer &Obj) : ptr(Obj.ptr) {}

SharedPointer::~SharedPointer() {}

SharedPointer::SharedPointer(IObject *Obj) : ptr(Obj) {}


void SharedPointer::reset(IObject *Obj)
{
    if (Obj == nullptr)
        this->ptr.reset();
    else
        ptr.reset(Obj);

}

void SharedPointer::swap(SharedPointer &Obj)
{
    return ptr.swap(Obj.ptr);
}

SharedPointer &SharedPointer::operator=(const SharedPointer &Obj)
{
    if (this != &Obj)
        this->ptr = Obj.ptr;
    return *this;
}

IObject *SharedPointer::operator->()
{
    return this->ptr.get();
}

IObject &SharedPointer::operator*()
{
    return *this->ptr;
}

std::size_t SharedPointer::use_count() const noexcept
{
    return this->ptr.use_count();
}
