/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-luca.martinet
** File description:
** unit_tests
*/

#include <criterion/criterion.h>

Test(my_squareroot_synthesis, negative_number)
{
    int result = my_squareroot_synthesis(-9);
    cr_assert_eq(result, -1);
}

Test(my_square_root_synthesis, zero)
{
    int result = my_squareroot_synthesis(0);
    cr_assert_eq(result, 0);
}

Test(my_squareroot_synthesis, perfect_square)
{
    int result = my_squareroot_synthesis(16);
    cr_assert_eq(result, 4);
}

Test(my_squareroot_synthesis, non_perfect_square)
{
    int result = my_squareroot_synthesis(10);
    cr_assert_eq(result, 3);
}

Test(my_squareroot_synthesis, large_number)
{
    int result = my_squareroot_synthesis(123456789);
    cr_assert_eq(result, 11111);
}