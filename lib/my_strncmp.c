/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

long my_strncmp(char *s1, char *s2, size_t n)
{
    size_t i = 0;

    while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    if (i == n) {
        return 0;
    }
    return s1[i] - s2[i];
}
