/*
** EPITECH PROJECT, 2024
** miniprintf
** File description:
** simplified printf
*/

#include "../../include/my.h"

int count;

void detected_percent(va_list *arg_list, char *s, int *i)
{
    void (*functions[14])(va_list *) = {&char_arg, &str_arg,
    &int_arg, &int_arg, &percent_percent, &float_arg, &arg_to_scientific,
    &uint_arg, &oct_arg, &hex_arg_lower, &arg_to_scientific_upper,
    &hex_arg_upper, &pointer_arg, &g_arg};
    int case_found = 0;
    int width = 0;

    for (int j = 0; CASES[j] != '\0'; j++) {
        if (CASES[j] == s[*i + 1]) {
            (*functions[j])(arg_list);
            case_found = 1;
        }
    }
    if (case_found == 0) {
        my_putchar('%');
        count += 1;
    } else
        *i += 1;
}

int my_printf(char *format, ...)
{
    va_list arg_list;
    int s_len = 0;
    int i = 0;

    count = 0;
    s_len = my_strlen(format);
    va_start(arg_list, format);
    while (i < s_len) {
        if (format[i] == '%') {
            detected_percent(&arg_list, format, &i);
        } else {
            my_putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(arg_list);
    return count;
}
