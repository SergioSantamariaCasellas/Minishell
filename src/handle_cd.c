/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

void go_to_home(command_t *command, char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            command->main_path = env[i] + 5;
            break;
        }
    }
    chdir(command->main_path);
}

int handle_cd(command_t *command, char **env)
{
    if (command->args[1] == NULL) {
        go_to_home(command, env);
    } else if (chdir(command->args[1]) != 0) {
            perror("cd");
    }
    return 1;
}
