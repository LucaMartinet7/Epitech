/*
** EPITECH PROJECT, 2022
** test
** File description:
** yessir
*/
#include <criterion/criterion.h>
Test(my_strdup, task01_day_08)
{
    char *test = my_strdup("HelloWorld");
    cr_assert_str_eq(test, "HelloWorld");
}
