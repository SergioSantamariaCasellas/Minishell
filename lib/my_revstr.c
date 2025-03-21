/*
** EPITECH PROJECT, 2024
** task 03 my_revstr
** File description:
** Swap each string character and return it
*/
#include "../include/my.h"

void swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int i;
    int length = my_strlen(str);

    for (i = 0; i < length / 2; i++) {
        swap(&str[i], &str[length - i - 1]);
    }
    return str;
}
