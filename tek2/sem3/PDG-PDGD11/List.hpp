/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** List
*/

#ifndef LIST_HPP_
#define LIST_HPP_

#include "IObject.hpp"
#include <iostream>
#include <string>
#include <vector>

class List {
    public:
        List();
        ~List();
        bool empty() const;
        std::size_t size() const;
        IObject*& front();
        IObject* front() const;
        IObject*& back();
        IObject* back() const;
        void pushBack(IObject *Obj);
        void pushFront(IObject *Obj);
        void popFront();
        void popBack();
        void clear();
        void forEach(void(*function)(IObject *Obj));

        class InvalidOperationException : public std::exception {};

    private:
        std::vector<IObject *> list;
};

#endif /* !LIST_HPP_ */
