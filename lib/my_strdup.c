/*
** EPITECH PROJECT, 2024
** hola
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my.h"

char *my_strdup(char *str)
{
    int len;
    char *dup;

    len = my_strlen(str) + 1;
    dup = malloc(len);
    if (dup == NULL)
        return (NULL);
    dup = my_strcpy(dup, str);
    dup[len - 1] = '\0';
    return (dup);
}
