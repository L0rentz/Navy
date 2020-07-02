/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#ifndef READ_SIZE
#define READ_SIZE (10000)
#endif /* !GNL*/

#ifndef ABS_MAC
#define ABS(value) ((value) < (0) ? ((value) * (-1)) : (value))
#endif /* !ABS_MAC */

int my_strlen(char *str);
void my_putstr(char *str);
char *my_strcpy(char *dest, char *src);
char *get_next_line(int fd);
int my_put_nbr(int nb);
int my_atoi(char const *str);
char *strnbr(int n);

#endif /* !UTILS_H_ */