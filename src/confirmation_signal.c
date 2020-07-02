/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** confirmation_signal
*/

#include "my.h"

int send_hit_confirmation(int receiver, int hit)
{
    int err = 0;
    usleep(8000);
    if (hit == 1)
        err = kill(receiver, SIGUSR1);
    else
        err = kill(receiver, SIGUSR2);
    return (err);
}

void attack_handler(int signum)
{
    if (signum == SIGUSR1)
        sig = -10;
    if (signum == SIGUSR2)
        sig = -20;
}

int receive_hit_confirmation(void)
{
    while (1) {
        signal(SIGUSR1, attack_handler);
        signal(SIGUSR2, attack_handler);
        if (sig == -10) {
            sig = -5;
            return (1);
        } else if (sig == -20) {
            sig = -5;
            return (0);
        }
        usleep(2000);
    }
}