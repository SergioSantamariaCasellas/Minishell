/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

void remove_env(int i, int size)
{
    for (int k = i; k < size - 1; k++) {
        environ[k] = environ[k + 1];
    }
    environ[size - 1] = NULL;
}

void check_env_for_un(char *str)
{
    int check_size = 0;

    while (environ[check_size]) {
        check_size++;
    }
    for (int j = 0; j < check_size; j++) {
        if (my_strncmp(environ[j], str, my_strlen(str)) == 0
            && environ[j][my_strlen(str)] == '=') {
            remove_env(j, check_size);
            break;
        }
    }
}

int handle_unsetenv(command_t *command, char **env)
{
    if (command->args[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        exit(1);
    }
    for (int i = 1; command->args[i] != NULL; i++) {
        check_env_for_un(command->args[i]);
    }
    return 1;
}

int handle_env(command_t *command, char **env)
{
    env = environ;
    while (*env) {
        my_printf("%s\n", *env);
        env++;
    }
    return 1;
}
