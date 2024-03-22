/*
** EPITECH PROJECT, 2022
** take_in_formation
** File description:
** take in formation
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/fonction.h"

char *check_data(void)
{
    size_t size = 1000;
    char *str = NULL;
    getline(&str, &size, stdin);
    return (str);
}

char **my_str_to_word_array_specific(char *str, char f);

void free_word(char **arrays)
{
    int n = 0;
    for (n = 0; arrays[n] != NULL; n++)
        free(arrays[n]);
    free(arrays);
}

char *upload_data(char *str)
{
    char *update_value = malloc(sizeof(char) * 1500);
    int g = 0, b = 0;
    for (g = 0; str[g] != '\0'; g++) {
        if (str[g] == ':' && str[g + 1] >= '0' && str[g + 1] <= '9')
            break;
    }
    g = g + 1;
    for (g; str[g] != '\0'; g++, b++) {
        if (str[g] == ':' && str[g + 1] >= 65 && str[g + 1] <= 122)
            break;
        else
            update_value[b] = str[g];
    }
    return update_value;
}

float *true_value(char *str)
{
    char *tab = upload_data(str);
    int b = 0;
    char **val = my_str_to_word_array_specific(str, ':');
    float *value = malloc(sizeof(float) * 1000);
    for (b = 0; val[b + 3] != NULL;  b++) {
        value[b] = atof(val[b + 3]);
    }
    free(tab);
    return value;
}

void danger(float *inf)
{
    float v = 0;
    float f = 0;

    if (inf[15] > 2000)
        v = 1.0;
    else if (inf[15] >= 1500) {
        v = 0.8;
        f = 0.005;
    }
    else if (inf[15] >= 1000) {
        v = 0.6;
        f = 0.05;
    }
    else if (inf[15] >= 600) {
        v = 0.4;
        f = 0.1;
    }
    else if (inf[15] >= 400) {
        v = 0.2;
        f = 0.2;
    }
    else {
        v = 0.2;
        f = 0.3;
    }
    
    if (inf[0] > inf[31]) {
        dprintf(1, "WHEELS_DIR:%.1f\n", f);
        check_data();
    } else if (inf[0] < inf[31]) {
        dprintf(1, "WHEELS_DIR:-%.1f\n", f);
        check_data();
    } else {
        dprintf(1, "WHEELS_DIR:%.1f\n", f);
        check_data();
    }
    dprintf(1, "CAR_FORWARD:%.1f\n", v);
    check_data();
}

void condition(float *inf)
{
    danger(inf);
}

void stop_car(char *inf)
{
    int i = 0;

    for (i = 0; inf[i] != '\0'; i++) {
        
        if (inf[i] == ':' && inf[i + 1] == 'T' && inf[i + 2] == 'r'
            && inf[i + 3] == 'a' && inf[i + 4] == 'c' && inf[i + 5] == 'k') {
            dprintf(1, "STOP_SIMULATION\n");
            exit(0);
        }
    }
}

