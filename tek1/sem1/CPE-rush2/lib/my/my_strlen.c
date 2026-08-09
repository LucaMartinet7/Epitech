/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count number of caracter
*/

int my_strlen(char const *str)
{
    int compteur = 0;
    for (int i = 0; str[i] != '\0'; i++){
        compteur += 1;
    }
    return compteur;
}
