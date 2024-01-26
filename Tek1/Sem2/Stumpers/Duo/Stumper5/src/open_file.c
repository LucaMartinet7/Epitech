/*
** EPITECH PROJECT, 2023
** open_file file
** File description:
** stumper5
*/

#include "../include/duo.h"

char *open_file(char const *filepath)
{
    struct stat ap;
    int fd = open(filepath, O_RDONLY);
    char *buffer;

    if (fd == -1) {
        return NULL;
    }
    if (stat(filepath, &ap) == -1) {
        return NULL;
    }
    buffer = malloc(sizeof(char) * (ap.st_size + 1));
    if (buffer == NULL)
        return NULL;
    if (read(fd, buffer, ap.st_size) < 1)
        return NULL;
    buffer[ap.st_size] = '\0';
    close(fd);
    return buffer;
}

int check_space(char *file)
{
    int len = strlen(file);
    for (int i = 0; i < len; i++) {
        if (file[i] == 32)
            return EXIT_ERROR;
    }
    return 0;
}

char *open_and_random_words(char *file)
{
    FILE *fd = fopen(file, "r");
    size_t len = 0;
    char *word = NULL;
    int count = 0;
    int index = 0;

    if (fd == NULL)
        return NULL;
    while (getline(&word, &len, fd) != -1)
        count++;

    fseek(fd, 0, SEEK_SET);
    index = rand() % count;

    for (int i = 0; i <= index; i++)
        getline(&word, &len, fd);

    word[strcspn(word, "\n")] = 0;
    fclose(fd);
    return word;
}

void display_status(char *guess, int essaie)
{
    printf("%s\n", guess);
    printf("Tries: %d\n", essaie);
}

void try_guess(char charac, char *words, char *my_guess)
{
    for (int i = 0; i < my_strlen(words); i++)
        if (words[i] == charac)
            my_guess[i] = charac;
}
