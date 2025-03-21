/*
** EPITECH PROJECT, 2024
** hola
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my.h"

void my_put_nbr(long nb, int putzero)
{
    char buffer[24] = "";
    int index = 0;
    long nb_abs = ABS(nb);

    while (nb_abs > 0) {
        buffer[index] = (nb_abs % 10) + '0';
        nb_abs /= 10;
        index++;
    }
    if (putzero == 1) {
        buffer[my_strlen(buffer)] = '0';
        count++;
    }
    my_put_nbr2(nb, buffer);
}

void my_put_nbr2(long nb, char *buffer)
{
    if (nb < 0) {
        buffer[my_strlen(buffer)] = '-';
        count++;
    }
    if (nb == 0) {
        buffer[0] = '0';
        count++;
    }
    my_revstr(buffer);
    my_putstr(buffer);
    count += my_strlen(buffer);
}
