/*
** EPITECH PROJECT, 2024
** CPP-Rtype
** File description:
** Collidable
*/

#ifndef COLLIDABLE_H_
    #define COLLIDABLE_H_

    struct Collidable {
        Collidable(bool is_collidable = true) : is_collidable(is_collidable) {}
        bool is_collidable;
    };


#endif /* !COLLIDABLE_H_ */
