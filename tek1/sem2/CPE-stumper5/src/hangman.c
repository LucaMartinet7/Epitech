/*
** EPITECH PROJECT, 2023
** hangman
** File description:
** hangman
*/

#include "../include/duo.h"

int process_guess(char letter, char *words, char *my_guess, int essaie)
{
    if (strchr(words, letter) == NULL) {
        fprintf(stderr, "%c: is not in this word\n", letter);
        essaie--;
    } else {
        try_guess(letter, words, my_guess);
    }
    return essaie;
}

int function_gameover_check(char *words, char *my_guess, int essaie)
{
    if (strcmp(words, my_guess) == 0) {
        return 1;
    }
    if (essaie == 0) {
        return 1;
    }
    return 0;
}

char *init_guess(char *words)
{
    char *my_guess = malloc(strlen(words) + 1);
    if (my_guess == NULL)
        return NULL;
    memset(my_guess, '*', strlen(words));
    my_guess[strlen(words)] = '\0';
    return my_guess;
}

int end_game(char *words, char *my_guess, int essaie)
{
    if (essaie > 0) {
        printf("%s\nTries: %d\n\nCongratulations!\n", my_guess, essaie);
    } else {
        printf("You lost!\n");
    }
    free(words);
    free(my_guess);
    return 0;
}

int my_hangman(char *file, int essaie)
{
    srand(time(NULL));
    char *words = open_and_random_words(file);
    char *my_guess = init_guess(words);
    char letter;

    if (check_space(words) == EXIT_ERROR)
        return EXIT_ERROR;
    if (!words)
        return EXIT_ERROR;
    while (essaie > 0) {
        display_status(my_guess, essaie);
        printf("\n");
        printf("Your letter: ");
        scanf(" %c", &letter);
        essaie = process_guess(letter, words, my_guess, essaie);
        if (function_gameover_check(words, my_guess, essaie)) {
            return end_game(words, my_guess, essaie);
        }
    }
    return end_game(words, my_guess, essaie);
}
