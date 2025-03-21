/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

int main(int argc, char **argv, char **env)
{
    info_t *info = malloc(sizeof(info_t));
    command_t *command = malloc(sizeof(command_t));

    if (info == NULL) {
        return 84;
    }
    if (command == NULL) {
        return 84;
    }
    initialize_contents(info, command);
    create_prompt(info, command, env);
    free(info);
    free(command);
    return 0;
}
