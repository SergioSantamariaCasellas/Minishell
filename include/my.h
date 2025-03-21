/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef MY_H
    #define MY_H
    #define ABS(value) (value < 0) ? (-value) : (value)
    #define CASES "csdi%feuoxEXpg"
    #define MAX_ARGS 60
    #include <stdlib.h>
    #include <stdio.h>
    #include <event.h>
    #include <unistd.h>
    #include <math.h>
    #include <string.h>
    #include <stdarg.h>
    #include <limits.h>
    #include <sys/wait.h>
    #include <wait.h>
extern int count;
extern char **environ;

typedef struct info_s {
    char *exitT;
    char *buffer;
    size_t buffsize;
    ssize_t characters;
    int exists;
    char **environment;
} info_t;

typedef struct command_s {
    char *args[MAX_ARGS];
    char *token;
    pid_t pid;
    int status;
    char full_path[1024];
    int j;
    char *path;
    char *path_copy;
    char *dir;
    int directory_length;
    int command_length;
    int pathCheck;
    char *pathArgument;
    char *main_path;
    int len;
    char *new_environment;
    int size_of_env;
    char **new_env;
    int size_env_check_rm;
} command_t;

//my_str_to_word_array
char **my_str_to_word_array(char *str);
int is_alphanum(char c);
int get_word_length(const char *start);
char *my_strdup_length(const char *start, int length);
int get_max_words(char *str);
static int count_alphanum(int i, char *str);
//lib functions
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char *str);
long my_strcmp(char *s1, char *s2);
long my_strncmp(char *s1, char *s2, size_t n);
char *my_strlowcase(char *s);
long str_to_int(char *str);
float string_to_float(char *str);
static float get_after_point(char *str, int i);
int is_float(char *str);
int is_digit(char c);
char *int_to_str(int num);
static char *int_to_str2(int num, char *str, int length, int is_neg);
double power(double base, int exponent);
int get_int_len(int n);
int my_put_nbr1(int nb);
//display functions
void my_putchar(char c);
int my_putstr(char const *str);
void my_put_nbr(long nb, int putzero);
void my_put_nbr2(long nb, char *buffer);
int my_put_float(double num);
int print_decimal(double decimal);
int put_scientific(double num, int upper);
void put_scientific2(int div_ten, int mult_ten, double num, int upper);
void get_power(int *div_ten, int *mult_ten, double *num);
int my_put_uint(unsigned long nb);
static int print_zeros(int n);
int convert_to_octal(int decimal);
int convert_to_hexadecimal(int num, int upper);
int put_pointer(void *pt);
char *fill_hex(unsigned long addr, char *h_chars, char *h, int *i);
void g_arg(va_list *arg_list);
//printf
int my_printf(char *format, ...);
void detected_percent(va_list *arg_list, char *s, int *i);
//conversion functions
void char_arg(va_list *arg_list);
void str_arg(va_list *arg_list);
void int_arg(va_list *arg_list);
void float_arg(va_list *arg_list);
void percent_percent(va_list *arg_list);
void arg_to_scientific(va_list *arg_list);
void uint_arg(va_list *arg_list);
void oct_arg(va_list *arg_list);
void hex_arg_lower(va_list *arg_list);
void hex_arg_upper(va_list *arg_list);
void arg_to_scientific_upper(va_list *arg_list);
void pointer_arg(va_list *arg_list);
// MINISHELL 1
int initialize_contents(info_t *info, command_t *command);
int create_prompt(info_t *info, command_t *command, char **env);
int nested_conditionals_contents(info_t *info, command_t *command, char **env);
int check_command(info_t *info, command_t *command, char **env);
int check_path(info_t *info, command_t *command, char **env);
int get_path_command(command_t *command, char **env);
int execve_commands(command_t *command, char **env);
int handle_compared_commands(command_t *command, char **env);
int execute_command(info_t *info, command_t *command, char **env);
//handling commands that are built in
int handle_cd(command_t *command, char **env);
void go_to_home(command_t *command, char **env);
int handle_setenv(command_t *command, char **env);
int create_new_env_check(command_t *command, char **env);
int copy_to_new_env(command_t *command, char **env);
int handle_unsetenv(command_t *command, char **env);
void check_env_for_un(char *str);
void remove_env(int index, int env_size);
int handle_env(command_t *command, char **env);
int check_start(const char *str, const char *prefix);
int handle_end(info_t *info, command_t *command, char **env);
void remove_line(info_t *info, command_t *command, char **env);
int handle_input(info_t *info, command_t *command, char **env);
int compare_exit(info_t *info);
#endif
