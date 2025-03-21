/*
** EPITECH PROJECT, 2024
** conversions
** File description:
** different functions to print every conversion specifier
*/

#include "../../include/my.h"

int put_pointer(void *pt)
{
    unsigned long address = (unsigned long)pt;
    char hex_char[] = "0123456789abcdef";
    char *hex_address = malloc(sizeof(char) * 20);
    int i = 0;

    if (address == 0) {
        my_strcpy(hex_address, "(nil)");
    }
    my_strcpy(hex_address, " ");
    hex_address = fill_hex(address, hex_char, hex_address, &i);
    i++;
    hex_address[i] = 'x';
    i++;
    hex_address[i] = '0';
    my_revstr(hex_address);
    hex_address[i] = '\0';
    count += my_strlen(hex_address);
    my_putstr(hex_address);
    free(hex_address);
}

char *fill_hex(unsigned long addr, char *h_chars, char *h, int *i)
{
    while (addr > 0) {
        (*i)++;
        h[*i] = h_chars[addr % 16];
        addr /= 16;
    }
    return h;
}

void g_arg(va_list *arg_list)
{
    int div_ten = 0;
    int mult_ten = 0;
    double num = va_arg(*arg_list, double);
    double num_abs = ABS(num);

    get_power(&div_ten, &mult_ten, &num_abs);
    if ((div_ten >= -4 && div_ten < 6) && (mult_ten >= -4 && mult_ten < 6))
        my_put_float(num);
    else
        put_scientific(num, 0);
}
