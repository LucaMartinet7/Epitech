/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
    #define SHAREDPOINTER_HPP_

#include "IObject.hpp"
#include <cstddef>
#include <memory>

class SharedPointer {
    public:
        SharedPointer();
        SharedPointer(IObject *Obj);
        SharedPointer(const SharedPointer &Obj);
        ~SharedPointer();
        void reset(IObject *Obj = nullptr);
        void swap(SharedPointer &Obj);
        std::size_t use_count() const noexcept;

        SharedPointer &operator=(const SharedPointer &Obj);
        IObject *operator->();
        IObject &operator*();

    protected:
    private:
        std::shared_ptr<IObject> ptr;
};

#endif /* !SHAREDPOINTER_HPP_ */
