/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** stumper
*/

char *int_to_arr(int nb)
{
    int i = 0;
    int tmp = nb;
    char *str = malloc(sizeof(char) * 100);
    if (str == NULL)
        return NULL;
    for (i = 0; tmp > 0; i++) {
        tmp /= 10;
    }
    str[i] = '\0';
    for (i = i - 1; i >= 0; i--) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    return str;
}

char *write_number_to_buffer(int nb, char *buffer)
{
    int i = 0;
    for (i = 0; buffer[i] != '\0'; i++);
    char *number = my_itoa(nb);
    for (int j = 0; number[j] != '\0'; j++, i++)
        buffer[i] = number[j];
    buffer[i] = '\n';
    buffer[i + 1] = '\0';
    free(number);
    return (buffer);
}

void write_save(food_element_s *food)
{
    char *buffer = malloc(sizeof(char) * 100);
    if (buffer == NULL)
        return NULL;
    int fd = open(".save", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
        return;
    buffer[0] = '\0';
    write_number_to_buffer(food->tomatos, buffer);
    write_number_to_buffer(food->dough, buffer);
    write_number_to_buffer(food->onion, buffer);
    write_number_to_buffer(food->pasta, buffer);
    write_number_to_buffer(food->olives, buffer);
    write_number_to_buffer(food->pepper, buffer);
    write_number_to_buffer(food->ham, buffer);
    write_number_to_buffer(food->cheese, buffer);
    write(fd, buffer, my_strlen(buffer));
    free(buffer);
}

char* do_getline(FILE *stream)
{
    size_t size = 0;
    char *buffer2 = NULL;

    getline(&buffer2, &size, stream);
    return buffer2;
}
