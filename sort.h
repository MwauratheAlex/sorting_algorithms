#ifndef SORT_H
#define SORT_H

#include <stdio.h>

/**
 * struct listint - doubly linked list
 *
 * @n: integer
 *
 * @next: pointer to next node
 *
 * @prev: pointer to previous node
 *
 * Description: Doubly linked list
 *
 */
typedef struct listint
{
	int n;
	struct listint *prev;
	struct listint *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */
