/*
** EPITECH PROJECT, 2024
** hola
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *str)
{
    char *dest_end = dest;

    dest_end += my_strlen(dest_end);
    while (*str != '\0') {
        *dest_end = *str;
        dest_end++;
        str++;
    }
    *dest_end = '\0';
    return dest;
}
