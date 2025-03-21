/*
** EPITECH PROJECT, 2024
** hola
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../../include/my.h"

void get_power(int *div_ten, int *mult_ten, double *num)
{
    while (*num < 1) {
        *num = *num * 10.0;
        (*div_ten)--;
    }
    while (*num > 10) {
        *num = *num / 10.0;
        (*mult_ten)++;
    }
}

void put_scientific2(int div_ten, int mult_ten, double num, int upper)
{
    int putzero = 0;

    my_put_float(num);
    if (upper == 1)
        my_putchar('E');
    else
        my_putchar('e');
    if (div_ten == 0 && mult_ten != 0) {
        my_putchar('+');
        count++;
    }
    if ((div_ten > -10 && mult_ten == 0) || (mult_ten < 10 && div_ten == 0))
        putzero = 1;
    if ((div_ten != 0 && mult_ten == 0))
        my_put_nbr(div_ten, putzero);
    else
        my_put_nbr(mult_ten, putzero);
}

int put_scientific(double num, int upper)
{
    int div_ten = 0;
    int mult_ten = 0;

    if (num == 0) {
        if (upper == 1)
            my_putstr("0.000000e+00");
        else
            my_putstr("0.000000E+00");
        count += 12;
        return 0;
    }
    if (num < 0) {
        my_putchar('-');
        num = num * (-1);
        count++;
    }
    get_power(&div_ten, &mult_ten, &num);
    put_scientific2(div_ten, mult_ten, num, upper);
    return 0;
}

void arg_to_scientific(va_list *arg_list)
{
    double a;

    a = va_arg(*arg_list, double);
    put_scientific(a, 0);
}

void arg_to_scientific_upper(va_list *arg_list)
{
    double a;

    a = va_arg(*arg_list, double);
    put_scientific(a, 1);
}
