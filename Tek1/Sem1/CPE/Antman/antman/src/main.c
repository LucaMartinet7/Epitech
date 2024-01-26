/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-2-antman-luca.martinet
** File description:
** main.c
*/

#include "../include/antman.h"

char **create_array(char *buf)
{
    char **arr;
    int word = 0;
    int letter = 0;
    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] != '\n' && buf[i] != ' ') {
            arr[word][letter] = buf[i];
            letter++;
        } else
            word++;
    }
}

char *compress(char *buf, size_t size)
{
    char *bufout = malloc(sizeof(char) * (size + 1));
    char **arr = create_array(buf);
    for (int i = 0; arr[i] != NULL; i++)
        printf("%s\n", arr[i]);
    return bufout;
}

int main(int ac, char **av)
{
    int input = open(av[1], O_RDONLY); // opening input file
    if (input == -1)
        return 84;
    int output = open(av[2], O_WRONLY | O_CREAT); // opening output file (compressed.data)
    struct stat st;
    if(stat(av[1], &st) == -1)
        return 84;
    int size = st.st_size; // length
    char *buf = malloc(sizeof(char) * (size + 1));
    if (read(input, buf, size) <= 0)
        return 84;
    buf[st.st_size] = '\0';
    char *buffer = compress(buf, size);
    printf("%s\n", buffer);
    int compressed_size = size; // the size of the compressed data
    if (write(output, buffer, compressed_size) <= 0)
        return 84;
    printf("%s\n", "test6");
    close(input);
    close(output);
    free(buf);
    free(buffer);
    return 0;
}

