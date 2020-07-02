/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#include "utils.h"

int sig;

char **load_map(char *pos, int who);
int check_pid(int ac, char **av);
void free_map(char **my_map, char **his_map);
void print_map(char **my_map, char **his_map);
int write_pid(int ac, char **av);
int check_ships_positions(char *filepath);
void write_info(void);
int send_pid(char *receiver);
void pid_usr_handler(int signum);
int receive_pid();
int check_attack(char *str);
int send_attack(int receiver, char *attack);
char *receive_attack(void);
int check_if_hit(char **my_map, char *attack);
int send_hit_confirmation(int receiver, int hit);
void attack_handler(int signum);
int receive_hit_confirmation(void);
int turn_zero(int *pid, char **my_map, int *turn, char **his_map);
int turn_one(int *pid, char **my_map, int *turn, char **his_map);
void print_hit(char **map, char hit, char *pos);
int check_lose_win(char **my_map, int *win);

#endif /* !MY_H_ */
