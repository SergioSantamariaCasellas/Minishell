/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

int create_new_env_check(command_t *command, char **env)
{
    //error handling in case there is no content insiide the setenv, when trying to change the environment variable   
    for (int i = 0; command->args[i] ; i++) {
        if (command->args[i] == NULL) {
            perror("Not enough commands to hadle the new environment");
            exit(1);
        }
    }
    command->len = my_strlen(command->args[1]) +
        my_strlen(command->args[2]) + 2;
    command->new_environment = malloc(command->len);
    my_strcpy(command->new_environment, command->args[1]);
    my_strcat(command->new_environment, " ");
    my_strcat(command->new_environment, "=");
    my_strcat(command->new_environment, " ");
    my_strcat(command->new_environment, command->args[2]);
    for (int i = 0; environ[i]; i++) {
        if (my_strncmp(environ[i], command->args[1],
            my_strlen(command->args[1])) == 0
            && environ[i][my_strlen(command->args[1])] == '=') {
            environ[i] = command->new_environment;
            return 1;
        }
    }
    return 1;
}

int copy_to_new_env(command_t *command, char **env)
{
    while (environ[command->size_of_env]) {
        command->size_of_env++;
    }
    command->new_env = malloc(sizeof(char *) * (command->size_of_env + 2));
    for (int i = 0; i < command->size_of_env; i++) {
        command->new_env[i] = environ[i];
    }
    command->new_env[command->size_of_env] = command->new_environment;
    command->new_env[command->size_of_env + 1] = NULL;
    environ = command->new_env;
    return 1;
}

int handle_setenv(command_t *command, char **env)
{
    create_new_env_check(command, env);
    copy_to_new_env(command, env);
    return 1;
}
