/*
** EPITECH PROJECT, 2024
** my_strlowcase
** File description:
** Converts every letters to lowercase
*/

#include "../include/my.h"

char *my_strlowcase(char *s)
{
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] >= 65 && s[i] <= 90) {
            s[i] += 32;
        }
        i++;
    }
    return s;
}
