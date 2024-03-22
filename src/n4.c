/*
** EPITECH PROJECT, 2022
** n4s
** File description:
** n4s
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/fonction.h"
#include <string.h>

char *check_data();
float *true_value(char *str);
void condition(float *inf);
void danger(float *inf);
void stop_car(char *inf);

void printf_vle(float *val)
{
    int y = 0, b = 0, k = 0, v = 0;
    for (b = 0; b < 32; b++)
        dprintf(2, "%.2f\n", val[b]);
    dprintf(2, "\n");
}

void start_option(void)
{
    size_t size = 32;
    ssize_t g;
    char *val = NULL;
    float *vle;
    float n = 0.3;

    my_putstr("START_SIMULATION\n");
    check_data();
    my_putstr("CAR_FORWARD:0.1\n");
    check_data();
    while (1) {
        dprintf(1, "GET_INFO_LIDAR\n");
        val = check_data();
        stop_car(val);

        if (strlen(val) > 40) {
            vle = true_value(val);
            danger(vle);
        }
    }
}

void main(int ac, char **av)
{
    start_option();
}
