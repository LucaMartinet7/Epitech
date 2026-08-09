/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** calendar
*/

#ifndef CALENDAR_H_
    #define CALENDAR_H_

typedef struct employee_s {
    char *id;
    char *last_name;
    char *first_name;
    char *position;
    char *zip_code;
    struct employee_s *next;
} employee_t;

typedef struct meeting_s {
    int id;
    char *day;
    char *zipcode;
    struct meeting_s *next;
} meeting_t;

char **strwarr(char *str, char c);
int manage_employee_struct(char *str, employee_t **employee);
void create_employee(char *str, employee_t **employee);
void free_func(char **arr);
int employee_print(employee_t *first, char *str);
int arr_len(char **arr);

int bubble_sort(employee_t *start, int (*compare)
(const employee_t *, const employee_t *));

int compare_name(const employee_t *first, const employee_t *second);
int compare_forname(const employee_t *first, const employee_t *second);
int compare_job(const employee_t *first, const employee_t *second);
int compare_zip(const employee_t *first, const employee_t *second);
int compare_id(const employee_t *first, const employee_t *second);

int bubble_sort_name(employee_t *start, char *str);
int bubble_sort_forename(employee_t *start, char *str);
int bubble_sort_job(employee_t *start, char *str);
int bubble_sort_zip(employee_t *start, char *str);
int bubble_sort_id(employee_t *start, char *str);

#endif /* !CALENDAR_H_ */
