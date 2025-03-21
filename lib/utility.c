/*
** EPITECH PROJECT, 2024
** utility
** File description:
** utility
*/

#include "../include/my.h"

long str_to_int(char *str)
{
    long num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            num = num * 10 + (str[i] - 48);
        } else {
            break;
        }
    }
    return num;
}

float string_to_float(char *str)
{
    int i = 0;
    float num = 0.0;
    int sign = 1;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.') {
        i++;
        num += get_after_point(str, i);
    }
    num *= sign;
    num = ((int)(num * 1000000 + 0.5)) / 1000000.0;
    return num;
}

static float get_after_point(char *str, int i)
{
    float after_point = 0.0;
    float div_counter = 1.0;

    while (str[i] >= '0' && str[i] <= '9') {
        after_point = after_point * 10 + (str[i] - '0');
        div_counter *= 10;
        i++;
    }
    return after_point / div_counter;
}

int is_float(char *str)
{
    int i = 0;
    int point_counter = 0;

    while (str[i] != '\0') {
        if (!(is_digit(str[i]) || str[i] == '.' || str[i] == '-'))
            return 0;
        if (str[i] == '.')
            point_counter++;
        i++;
    }
    if (point_counter > 1)
        return 0;
    return 1;
}

int is_digit(char c)
{
    if (c <= '9' && c >= '0')
        return 1;
    return 0;
}

char *int_to_str(int num)
{
    int is_neg = 0;
    int length = 0;
    int temp = num;
    char *str = NULL;

    if (num < 0) {
        is_neg = 1;
        num = -num;
        length++;
    }
    if (num == 0) {
        length = 1;
    } else {
        while (temp != 0) {
            length++;
            temp /= 10;
        }
    }
    str = (char *)malloc((length + 1) * sizeof(char));
    return int_to_str2(num, str, length, is_neg);
}

static char *int_to_str2(int num, char *str, int length, int is_neg)
{
    int i = length - 1;

    str[length] = '\0';
    if (num == 0)
        str[0] = '0';
    while (num > 0) {
        str[i] = (num % 10) + '0';
        num /= 10;
        i--;
    }
    if (is_neg)
        str[0] = '-';
    return str;
}
