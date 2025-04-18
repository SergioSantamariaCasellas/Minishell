/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Reproduce strcmp behaviour
*/

#include "../include/my.h"

long my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return s1[i] - s2[i];
}
