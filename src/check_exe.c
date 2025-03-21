/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hola
*/

#include "../include/my.h"

int execute_command(info_t *info, command_t *command, char **env)
{
    while (command->dir != NULL) {
        command->directory_length = my_strlen(command->dir);
        command->command_length = my_strlen(command->args[0]);
        if (command->directory_length + command->command_length
            + 2 <= sizeof(command->full_path)) {
            my_strcpy(command->full_path, command->dir);
            command->full_path[command->directory_length] = '/';
            my_strcpy(command->full_path + command->directory_length + 1,
                command->args[0]);
            command->full_path[command->directory_length +
                command->command_length + 1] = '\0';
        }
        if (access(command->full_path, X_OK) == 0) {
            command->args[0] = command->full_path;
            break;
        }
        command->dir = strtok(NULL, ":");
    }
    free(command->path_copy);
    return execve_commands(command, env);
}

int execve_commands(command_t *command, char **env)
{
    command->pid = fork();
    if (command->pid == -1) {
        perror("fork");
        return 1;
    }
    if (command->pid == 0) {
        execve(command->args[0], command->args, environ);
        my_printf("%s: Command not found.\n", command->args[0]);
        exit(1);
    } else {
        waitpid(command->pid, &command->status, 0);
    }
    if (WIFEXITED(command->status)) {
        return WEXITSTATUS(command->status);
    }
    return 0;
}

int handle_compared_commands(command_t *command, char **env)
{
    if (my_strcmp(command->args[0], "cd") == 0)
        return handle_cd(command, env);
    if (my_strcmp(command->args[0], "setenv") == 0)
        return handle_setenv(command, env);
    if (my_strcmp(command->args[0], "unsetenv") == 0)
        return handle_unsetenv(command, env);
    if (my_strcmp(command->args[0], "env") == 0)
        return handle_env(command, env);
    return 0;
}

int check_start(const char *str, const char *start)
{
    while (*start) {
        if (*start != *str)
            return 0;
        start++;
        str++;
    }
    return 1;
}

int check_path(info_t *info, command_t *command, char **env)
{
    command->pathCheck = 0;
    command->pathArgument = command->args[0];
    while (*command->pathArgument != '\0') {
        if (*command->pathArgument == '/') {
            command->pathCheck = 1;
            break;
        }
        command->pathArgument++;
    }
    if (command->pathCheck) {
        return execve_commands(command, env);
    } else {
        get_path_command(command, env);
        return execute_command(info, command, env);
    }
}
