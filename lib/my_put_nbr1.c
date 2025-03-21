/*
** EPITECH PROJECT, 2024
** hola
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my.h"

int my_put_nbr1(int nb)
{
    int num = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    num = nb % 10;
    if (nb > 9) {
        my_put_nbr1(nb / 10);
    }
    my_putchar(num + 48);
    return 0;
}
