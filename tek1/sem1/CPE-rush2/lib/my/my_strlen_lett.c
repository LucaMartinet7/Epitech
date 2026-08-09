/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count number of caracter
*/

int my_strlen_lett(char const *str)
{
    int i = 0;
    int compteur = 0;
    for (i; str[i] != '\0'; i++){
        if (str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123) {
            compteur += 1;
        }
    }
    return compteur;
}
