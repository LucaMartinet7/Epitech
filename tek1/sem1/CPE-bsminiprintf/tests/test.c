/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(sum_numbers, return_sum_numbers)
{
    int ret = sum_numbers (3, 21, 25, -4) ;
    cr_assert_eq (ret, 42) ;
}
Test(sum_strings_length, sum_str_lengths ) {
    int value = sum_strings_length(5, "Hello", "a", "toto", "","plop") ;
    cr_assert_eq(value, 14) ;
}
Test(disp_stdarg, basic, .init=cr_redirect_stdout) {
    disp_stdarg("csiis", 'X', "hi", 10, -3, "plop");
    cr_assert_stdout_eq_str("Xnhin10n-3nplopn"," ");
}
