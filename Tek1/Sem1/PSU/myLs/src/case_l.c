/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-2-myls-luca.martinet
** File description:
** case_l.c
*/

#include "../include/my.h"

void outplayed_for_l(struct dirent *file, struct stat info)
{
    struct passwd *p;
    struct group *g;
    char *date;

    p = getpwuid(info.st_uid);
    g = getgrgid(info.st_gid);
    date = ctime(&info.st_ctime);
    date = date_cp(&date[4]);
    if (file->d_name[0] != '.') {
        print_perms(info.st_mode, info);
        my_printf("%i", info.st_nlink);
        my_printf("%s, %s", p->pw_name, g->gr_name);
        my_printf("%u", info.st_size);
        my_printf("%s, %s", date, file->d_name);
        free(date);
    }
}

void print_perms(const mode_t mode, struct stat info)
{
    if (S_ISDIR(info.st_mode))
        my_putchar('d');
    else
        my_putchar('-');
    (mode & S_IRUSR) ? my_putchar('r') : my_putchar('-');
    (mode & S_IWUSR) ? my_putchar('w') : my_putchar('-');
    (mode & S_IXUSR) ? my_putchar('x') : my_putchar('-');
    (mode & S_IRGRP) ? my_putchar('r') : my_putchar('-');
    (mode & S_IWGRP) ? my_putchar('w') : my_putchar('-');
    (mode & S_IXGRP) ? my_putchar('x') : my_putchar('-');
    (mode & S_IROTH) ? my_putchar('r') : my_putchar('-');
    (mode & S_IWOTH) ? my_putchar('w') : my_putchar('-');
    (mode & S_IXOTH) ? my_putchar('x') : my_putchar('-');
    my_putchar('.');
    my_putchar(' ');
}

char *date_cp(char *date)
{
    int i = 0;
    char *src = malloc(sizeof(char) * 13);

    while (i < 12) {
        src[i] = date[i];
        i++;
    }
    src[i] = '\0';
    return (src);
    free(src);
}

int my_ls_l(char **av)
{
    struct dirent *file;
    struct stat info;
    my_printf("total %i\n", block_total(file, info, av));
    DIR *dir = opendir(av);

    if (dir == NULL)
        exit(1);
    while ((file = readdir(dir)) != NULL) {
        stat(file->d_name, &info);
        outplayed_for_l(file, info);
    }
    if (closedir(dir) == -1)
        exit(-1);
    free(file);
    return 0;
}
