/*
** EPITECH PROJECT, 2024
** display_functions
** File description:
** functions to display the conversions
*/

#include "../../include/my.h"

static int round_up(double num)
{
    int int_part = (int)num;
    double decimal = num - int_part;

    if (decimal > 0.5) {
        return int_part + 1;
    } else {
        return int_part;
    }
}

int my_put_float(double num)
{
    long integer = (long) num;
    double decimal = 0;

    decimal = num - (double)integer;
    my_put_nbr(integer, 0);
    my_putstr(".");
    count++;
    print_decimal(decimal);
    return 0;
}

int print_decimal(double decimal)
{
    double tmp = 0;
    int leftzero = 6;

    decimal = ABS(decimal * 1000000);
    decimal = round_up(decimal);
    tmp = decimal;
    while (tmp > 1) {
        tmp = tmp / 10;
        leftzero--;
    }
    if (decimal == 0) {
        my_putstr("000000");
        count += 6;
    } else {
        print_zeros(leftzero);
        my_put_nbr(decimal, 0);
    }
    return 0;
}

static int print_zeros(int n)
{
    for (int i = 0; i < n; i++) {
        my_putchar('0');
        count++;
    }
    return 0;
}

int my_put_uint(unsigned long nb)
{
    char buffer[24] = "";
    int index = 0;

    while (nb > 0) {
        buffer[index] = (nb % 10) + '0';
        nb /= 10;
        index++;
    }
    my_revstr(buffer);
    my_putstr(buffer);
    count += my_strlen(buffer);
    return 0;
}

int convert_to_octal(int decimal)
{
    long octalNumber = 0;
    int countVariable = 1;
    int decimal_Number;
    int remainder;

    decimal_Number = ABS(decimal);
    while (decimal_Number != 0) {
        remainder = decimal_Number % 8;
        octalNumber += remainder * countVariable;
        countVariable = countVariable * 10;
        decimal_Number /= 8;
    }
    if (decimal < 0) {
        octalNumber = (long)37777777777 - octalNumber + (long)1;
    }
    my_put_nbr(octalNumber, 0);
    return 0;
}

int convert_to_hexadecimal(int num, int upper)
{
    char hex_lower[] = "0123456789abcdef";
    char hex_upper[] = "0123456789ABCDEF";
    char *finalHex = malloc(sizeof(char) * 20);
    int i = 0;

    my_strcpy(finalHex, " ");
    while (num > 0) {
        i++;
        if (upper == 0)
            finalHex[i] = hex_lower[num % 16];
        if (upper == 1)
            finalHex[i] = hex_upper[num % 16];
        num /= 16;
    }
    my_revstr(finalHex);
    finalHex[i] = '\0';
    my_putstr(finalHex);
    count += my_strlen(finalHex);
    free(finalHex);
}
