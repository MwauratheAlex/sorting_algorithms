#include "sort.h"

/**
 * swap - swaps two nodes
 *
 * @a: first node
 *
 * @b: last node
 *
 * @head: head node
 *
 * Return: nothing
 */

void swap(listint_t *head, listint_t *a, listint_t *b)
{
	listint_t *temp;

	if (head == NULL || a == NULL || b == NULL)
		return;
	temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;
	if (a->prev)
		a->prev->next = a;
	if (b->prev)
		b->prev->next = b;
	temp = a->next;
	a->next = b->next;
	b->next = temp;
	if (a->next)
		a->next->prev = a;
	if (b->next)
		b->next->prev = b;

	if (a == head)
		head = b;
	else if (b == head)
		head = a;
}


/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: the list to sort
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;
	int swapped = 0;

	if (*list == NULL)
		return;
	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		while (temp != *list && temp->n < temp->prev->n)
		{
			swap(*list, temp->prev, temp);
			print_list(*list);
			temp = temp->prev;
			swapped = 1;
		}
		if (temp == *list)
			*list = temp;
		if (swapped == 1)
			swapped = 0;
		else
			current = current->next;
	}
}
