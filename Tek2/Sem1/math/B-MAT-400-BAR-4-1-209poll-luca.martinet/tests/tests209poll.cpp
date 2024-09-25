/*
** EPITECH PROJECT, 2024
** B-MAT-400-BAR-4-1-209poll-luca.martinet
** File description:
** tests209poll
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>

#include "poll.hpp"

void setup(void)
{
    cr_redirect_stdout();
}

Test(poll, get_variance, .init = setup)
{
    int pSize = 1000;
    int sSize = 100;
    double p = 0.5;
    double result = get_variance(pSize, sSize, p);
    cr_assert_float_eq(result, 0.00225, 0.00001);
}

Test(poll, print_result, .init = setup)
{
    int pSize = 10000;
    int sSize = 500;
    double p = 42.24;
    print_result(pSize, sSize, p);
    cr_assert_stdout_eq_str("Population size: \t\t10000\nSample size: \t\t\t500\nVoting intentions: \t\t42.24%\nVariance: \t\t\t0.000464\n95% confidence interval: \t[38.02%; 46.46%]\n99% confidence interval: \t[36.68%; 47.80%]\n");
}

// Test(poll, check_args)
// {
//     int pSize = 1000;
//     int sSize = 100;
//     double p = 0.5;
//     bool result = check_args(pSize, sSize, p);
//     cr_assert_eq(result, true);
// }
