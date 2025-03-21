/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

int get_int_len(int n)
{
    int len = 0;

    while (n > 0) {
        len++;
        n = n / 10;
    }
    return len;
}
