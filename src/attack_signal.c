/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** attack_signal
*/

#include "my.h"

int check_if_hit(char **my_map, char *attack)
{
    int line = (attack[1] - 48) + 1;
    int col = (attack[0] - 64) * 2;
    if (my_map[line][col] != '.' && my_map[line][col] != 'x'
    && my_map[line][col] != 'o')
        return (1);
    return (0);
}

int check_attack(char *str)
{
    if (my_strlen(str) != 2) return (1);
    if (str[0] < 'A' || str[0] > 'H') return (1);
    if (str[1] < '1' || str[1] > '8') return (1);
    return (0);
}

int send_attack(int receiver, char *attack)
{
    int err = 0;
    attack[0] -= 16;
    sig = -5;
    for (int i = 0; attack != NULL && attack[i] != '\0'; i++) {
        for (int j = -1; j != attack[i] - 48; j++) {
            usleep(8000);
            err = kill(receiver, SIGUSR1);
            if (err == -1) return (1);
        } usleep(8000);
        err = kill(receiver, SIGUSR2);
        if (err == -1) return (1);
    } usleep(8000);
    err = kill(receiver, SIGUSR2);
    return (err);
}

char *receive_attack(void)
{
    int nb = -1, i = 0;
    char *attack = malloc(sizeof(char) * 3);
    sig = -5;
    for (; sig != -2;) {
        signal(SIGUSR1, pid_usr_handler);
        signal(SIGUSR2, pid_usr_handler);
        usleep(2000);
        if (sig == -1 && nb != -1) {
            attack[i] = nb + 48;
            i++;
            nb = -1;
        } nb = sig;
    } attack[0] += 16;
    attack[2] = '\0';
    return (attack);
}