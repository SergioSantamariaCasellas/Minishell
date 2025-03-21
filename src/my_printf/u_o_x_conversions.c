/*
** EPITECH PROJECT, 2024
** conversions
** File description:
** different functions to print every conversion specifier
*/

#include "../../include/my.h"

void uint_arg(va_list *arg_list)
{
    unsigned int a;

    a = va_arg(*arg_list, unsigned int);
    my_put_uint(a);
}

void oct_arg(va_list *arg_list)
{
    int a;

    a = va_arg(*arg_list, int);
    convert_to_octal(a);
}

void hex_arg_lower(va_list *arg_list)
{
    int a;

    a = va_arg(*arg_list, int);
    convert_to_hexadecimal(a, 0);
}

void hex_arg_upper(va_list *arg_list)
{
    int a;

    a = va_arg(*arg_list, int);
    convert_to_hexadecimal(a, 1);
}
