/*
** EPITECH PROJECT, 2024
** conversions
** File description:
** different functions to print every conversion specifier
*/

#include "../../include/my.h"

void str_arg(va_list *arg_list)
{
    char *a;

    a = va_arg(*arg_list, char *);
    my_putstr(a);
    count += my_strlen(a);
}

void int_arg(va_list *arg_list)
{
    int a;

    a = va_arg(*arg_list, int);
    my_put_nbr(a, 0);
}

void percent_percent(va_list *arg_list)
{
    my_putchar('%');
    count += 1;
}

void char_arg(va_list *arg_list)
{
    char a;

    a = (char) va_arg(*arg_list, int);
    write(1, &a, 1);
    count += 1;
}

void float_arg(va_list *arg_list)
{
    double a;

    a = va_arg(*arg_list, double);
    count += my_put_float(a);
}
