/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-jules.dufraiche
** File description:
** raytracerTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
