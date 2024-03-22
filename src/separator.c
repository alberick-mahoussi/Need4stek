/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_n_letter(char *str, char f)
{
    int n = 0, j = 1;
    for (n = 0; str[n] != '\0'; n++) {
        if (str[n] == f)
            j++;
    }
    return j;
}

char **stock_two_d(int j)
{
    char **tab = malloc(sizeof(char *) * (j + 1));
    if (tab == NULL)
        return NULL;
    return tab;
}

char **check_line_and_row(int j, char *str, char f)
{
    char **tab = stock_two_d(j);
    int n = 0;
    int u = 0;
    int g = 0;
    while (g < j) {
        for (u = 0, n = 0; str[u] != f; u++, n++);
        tab[g] = malloc(sizeof(char) * (n + 1));
        n = 0;
        u = u + 1;
        g = g + 1;
    }
    return tab;
}

char **my_str_to_word_array_specific(char *str, char f)
{
    int k = 0, m = 0, j = 0;
    int i = check_n_letter(str, f);
    char **tab = check_line_and_row(i, str, f);

    for (k = 0; str[k] != '\0'; k++) {
        if (str[k] == f) {
            j++;
            m = 0;
        }
        else {
            tab[j][m] = str[k];
            m++;
        }
    }
    tab[j + 1] = NULL;
    return tab;
}
