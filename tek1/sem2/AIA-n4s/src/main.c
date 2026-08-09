/*
** EPITECH PROJECT, 2023
** B-AIA-200-PAR-2-2-n4s-luca.martinet
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include "../include/ai.h"

void check_angle(float turning_angle, float distance)
{
    if (turning_angle < -1) {
        turning_angle = -1;
    } else if (turning_angle > 1) {
        turning_angle = 1;
    } if (distance < 0.1) {
        dprintf(1, "WHEELS_DIR:%f\n", turning_angle);
    } else {
        dprintf(1, "WHEELS_DIR:0\n");
    }
}

int get_info_lidar(ai_t *ai)
{
    size_t size = 0;
    char *response = NULL;
    dprintf(1, "GET_INFO_LIDAR\n");
    if (getline(&response, &size, stdin) == -1)
        exit(1);
    char **array = my_str_to_word_array(response, ':');
    for (int i = 0; array[i]; i++) {
        ai->array[i] = atof(array[i]);
    }
    ai->mid = ai->array[15];
    if (check_finish(response) == 1) {
        exit (0);
    }
    return 0;
}

int get_turning_angle(ai_t *ai)
{
    float turning_angle = ai->array[0] - ai->array[31];
    dprintf(1, "WHEELS_DIR:%f\n", turning_angle);
    return 0;
}

void boucle(ai_t *ai)
{
    while (1) {
        get_info_lidar(ai);
        get_turning_angle(ai);
    }
}

int main(void)
{
    ai_t *ai = malloc(sizeof(ai_t));
    dprintf(1, "START_SIMULATION\n");
    dprintf(1, "CAR_FORWARD:0.5\n");
    boucle(ai);
    dprintf(1, "STOP_SIMULATION\n");
    return 0;
}
