/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

double power(double base, int exponent)
{
    double result = 1;

    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
