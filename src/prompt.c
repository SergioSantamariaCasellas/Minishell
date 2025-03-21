/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

int initialize_contents(info_t *info, command_t *command)
{
    command->j = 0;
    command->main_path = NULL;
    info->exitT = "exit";
    command->directory_length = 0;
    command->command_length = 0;
    command->pathCheck = 0;
    info->buffer = NULL;
    info->buffsize = 0;
    info->exists = isatty(STDIN_FILENO);
    return 0;
}

int create_prompt(info_t *info, command_t *command, char **env)
{
    while (1) {
        if (info->exists)
            my_printf("$> ");
        info->characters = getline(&info->buffer, &info->buffsize, stdin);
        if (handle_input(info, command, env))
            break;
    }
    free(info->buffer);
    return 0;
}

int nested_conditionals_contents(info_t *info, command_t *command, char **env)
{
    if (info->characters > 0 && info->buffer[info->characters - 1] == '\n') {
        info->buffer[info->characters - 1] = '\0';
        info->characters--;
    }
    if (info->characters == 0 || info->buffer[0] == '\0')
        return 1;
    if (my_strcmp(info->buffer, info->exitT) == 0)
        exit(0);
    check_command(info, command, env);
    return 1;
}

int get_path_command(command_t *command, char **env)
{
    for (env = environ; *env != NULL; env++) {
        if (check_start(*env, "PATH=")) {
            command->path = *env + 5;
            command->path_copy = my_strdup(command->path);
            command->dir = strtok(command->path_copy, ":");
            return 0;
        }
    }
    return 0;
}

int check_command(info_t *info, command_t *command, char **env)
{
    command->token = strtok(info->buffer, " \t\n");
    command->j = 0;
    while (command->token != NULL && command->j < MAX_ARGS - 1) {
        command->args[command->j] = command->token;
        command->j++;
        command->token = strtok(NULL, " \t\n");
    }
    command->args[command->j] = NULL;
    if (command->j == 0)
        return 1;
    if (handle_compared_commands(command, env))
        return 0;
    check_path(info, command, env);
    return 0;
}
