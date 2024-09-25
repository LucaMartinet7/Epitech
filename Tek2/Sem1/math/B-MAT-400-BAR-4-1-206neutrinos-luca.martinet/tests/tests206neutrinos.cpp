/*
** EPITECH PROJECT, 2024
** B-MAT-400-BAR-4-1-206neutrinos-luca.martinet [WSL: Ubuntu]
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>

#include <iostream>
#include <sys/types.h>

#include "neutrinos.hpp"

void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(neutrinos, test_bad_argument_error_message, .init=redirect_all_std)
{
    try {
        throw BadArgumentError("Test error message");
        cr_assert_fail("Exception was not thrown");
    } catch (const BadArgumentError& e) {
        cr_assert_str_eq(e.what(), "Test error message");
    }
}

Test(neutrinos, test_bad_argument_error_empty_message, .init=redirect_all_std)
{
    try {
        throw BadArgumentError("");
        cr_assert_fail("Exception was not thrown");
    } catch (const BadArgumentError& e) {
        cr_assert_str_eq(e.what(), "");
    }
}

Test(neutrinos, test_bad_argument_error_long_message, .init=redirect_all_std)
{
    std::string long_message(5000, 'a'); // Creating a long string
    try {
        throw BadArgumentError(long_message);
        cr_assert_fail("Exception was not thrown");
    } catch (const BadArgumentError& e) {
        cr_assert_str_eq(e.what(), long_message.c_str());
    }
}

Test(neutrinos, test_constructor_with_positive_values)
{
    Neutrinos obj(1, 2, 3, 4);
    cr_assert_eq(obj.getValue(), 1);
    cr_assert_eq(obj.getArithmetic(), 2);
    cr_assert_eq(obj.getHarmonic(), 3);
    cr_assert_eq(obj.getAverage(), 4);
}

Test(neutrinos, test_constructor_with_zero_values)
{
    try {
        Neutrinos obj(0, 0, 0, 0);
    } catch (const BadArgumentError& e) {
        cr_assert_fail("Constructor threw an unexpected BadArgumentError");
    }
    cr_assert(1); // If we reach this line, the test passes
}

Test(neutrinos, test_constructor_with_negative_values)
{
    try {
        Neutrinos obj(-1, -2, -3, -4);
        cr_assert_fail("Constructor did not throw an error with negative values");
    } catch (const BadArgumentError& e) {
        cr_assert_str_eq(e.what(), "You must pass positive arguments");
    }
}

Test(neutrinos, test_bad_argument_error_what, .init=redirect_all_std)
{
    BadArgumentError error("Test error message");
    cr_assert_str_eq(error.what(), "Test error message");
}

Test(neutrinos, test_loop_with_no_inputs, .init=redirect_all_std)
{
    std::stringstream ss;
    ss << "END\n";
    std::cin.rdbuf(ss.rdbuf());
    Neutrinos obj(12000, 297514, 297912, 4363);
    loop(obj);
    cr_assert_stdout_eq_str("");
}

Test(neutrinos, test_loop_with_negative_input, .init=redirect_all_std)
{
    std::stringstream ss;
    ss << "-299042\nEND\n";
    std::cin.rdbuf(ss.rdbuf());
    Neutrinos obj(12000, 297514, 297912, 4363);
    try {
        loop(obj);
        cr_assert_fail();
    } catch (const BadArgumentError& e) {
        cr_assert_str_eq(e.what(), "You must pass positive arguments");
    }
}

Test(neutrinos, test_loop_with_two_inputs, .init=redirect_all_std)
{
    std::stringstream ss;
    ss << "299042\n302420\nEND\n";
    std::cin.rdbuf(ss.rdbuf());
    Neutrinos obj(12000, 297514, 297912, 4363);
    loop(obj);
    cr_assert_stdout_eq_str("Number of values: 12001\nStandard deviation: 4362.84\nArithmetic mean: 297514.13\nRoot mean square: 297546.11\nHarmonic mean: 297912.09\n"
                            "Number of values: 12002\nStandard deviation: 4362.89\nArithmetic mean: 297514.54\nRoot mean square: 297546.52\nHarmonic mean: 297912.46\n");
}

Test(neutrinos, test_manHelp, .init=redirect_all_std)
{
    manHelp();
    cr_assert_stdout_eq_str("USAGE\n\t./206neutrinos n a h sd\n\nDESCRIPTION\n\tn\tnumber of values\n\ta\tarithmetic mean\n\th\tharmonic mean\n\tsd\tstandard deviation\n");
}

Test(neutrinos, test_setValue, .init=redirect_all_std)
{
    Neutrinos obj(12000, 297514, 297912, 4363);
    cr_assert_eq(obj.getValue(), 12000);
    cr_assert_eq(obj.getArithmetic(), 297514);
    cr_assert_eq(obj.getHarmonic(), 297912);
    cr_assert_eq(obj.getAverage(), 4363);
}
