/*
** EPITECH PROJECT, 2024
** B-NWP-400-BAR-4-1-myteams-jules.dufraiche
** File description:
** shared
*/

#include <stdbool.h>

#ifndef _SHARED_H_
    #define _SHARED_H_

    #define SUCCESS 0
    #define ERROR   84
    #define MAX_CLIENTS 10
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

/*Utils*/
bool is_number(const char *str);

#endif /* !_SHARED_H_ */
