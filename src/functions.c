/*
** EPITECH PROJECT, 2023
** params arrat
** File description:
** qwe
*/
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}

int my_str_isalpha(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if ((str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122)) {
            return 0;
        }
    }
    return 1;
}

int my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}


int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_str_isnum(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] > 57 || str[i] < 48) {
            return 0;
        }
    }
    return 1;
}

char *my_strupcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}
