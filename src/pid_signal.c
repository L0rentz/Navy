/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** pid_signal
*/

#include "my.h"

int send_pid(char *receiver)
{
    char *pid = strnbr(getpid());
    int err = 0;
    for (int i = 0; pid != NULL && pid[i] != '\0'; i++) {
        for (int j = -1; j != pid[i] - 48; j++) {
            usleep(8000);
            err = kill(my_atoi(receiver), SIGUSR1);
            if (err == -1) {
                free(pid);
                return (1);
            }
        } usleep(8000);
        err = kill(my_atoi(receiver), SIGUSR2);
        if (err == -1) {
            free(pid);
            return (1);
        }
    } usleep(8000);
    err = kill(my_atoi(receiver), SIGUSR2);
    free(pid);
    return (err);
}

void pid_usr_handler(int signum)
{
    if (signum == SIGUSR2) {
        if (sig == -1)
            sig = -2;
        else
            sig = -1;
    } else if (signum == SIGUSR1) {
        if (sig == -5)
            sig = 0;
        else
            sig++;
    }
}

int receive_pid(void)
{
    int nb = -1, i = 0;
    char pid[10] = {0};
    for (; sig != -2;) {
        signal(SIGUSR1, pid_usr_handler);
        signal(SIGUSR2, pid_usr_handler);
        usleep(2000);
        if (sig == -1 && nb != -1) {
            pid[i] = nb + 48;
            i++;
            nb = -1;
        } nb = sig;
    }
    return (my_atoi(pid));
}