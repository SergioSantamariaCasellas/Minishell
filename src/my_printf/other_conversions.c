/*
** EPITECH PROJECT, 2024
** conversions
** File description:
** different functions to print every conversion specifier
*/

#include "../../include/my.h"

void pointer_arg(va_list *arg_list)
{
    void *a;

    a = va_arg(*arg_list, void *);
    put_pointer(a);
}
