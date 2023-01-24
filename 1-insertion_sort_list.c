#include "sort.h"

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
	listint_t *current_node = (*list);
	listint_t *moving_node = (*list);
	listint_t *buffer = NULL;

	while (current_node)
	{
		current_node = current_node->next;
		moving_node = current_node->prev;
		buffer = moving_node;
		while (moving_node->prev && current_node->n < moving_node->n)
			moving_node = moving_node->prev;
		current_node->prev->next = current_node->next;
		current_node->prev = moving_node->prev;
		if (current_node->prev == NULL)
			(*list) = current_node;
		current_node->next = moving_node;
		moving_node->prev = current_node;
                current_node = buffer;
		print_list(*list);
	}
}
