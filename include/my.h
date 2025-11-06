/*
** EPITECH PROJECT, 2023
** workshop-unit-tests
** File description:
**
*/
#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>


void my_putchar(char c);
int my_putstr(char const *str);

int my_isneg(int nb);
int my_strlen(char const *str);

int my_str_isnum(char const *str);
char *my_strupcase(char *str);
int my_str_isalpha(char const *str);

#endif /*MY_H*/