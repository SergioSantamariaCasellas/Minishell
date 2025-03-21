/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

int handle_end(info_t *info, command_t *command, char **env)
{
    if (info->characters == -1) {
        if (info->exists)
            my_printf("\n");
        return 1;
    }
    return 0;
}

void remove_line(info_t *info, command_t *command, char **env)
{
    if (info->characters > 0 && info->buffer[info->characters - 1] == '\n') {
        info->buffer[info->characters - 1] = '\0';
        info->characters--;
    }
}

int compare_exit(info_t *info)
{
    if (my_strcmp(info->buffer, info->exitT) == 0)
        return 1;
    return 0;
}

int handle_input(info_t *info, command_t *command, char **env)
{
    if (handle_end(info, command, env))
        return 1;
    remove_line(info, command, env);
    if (info->characters == 0)
        return 0;
    if (compare_exit(info))
        return 1;
    check_command(info, command, env);
    return 0;
}
