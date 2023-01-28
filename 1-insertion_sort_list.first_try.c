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
	listint_t *previous_node = (*list);
	listint_t *current_node = previous_node->next;
	listint_t *buffer = NULL;

	while (current_node)
	{
		previous_node = current_node;
		if (current_node->next)
			current_node = previous_node->next;
		else
			break;

		if (current_node->n < previous_node->n)
		{
			buffer = current_node;
			previous_node->next = buffer->next;
			if (buffer->next)
				buffer->next->prev = previous_node;
			current_node = previous_node;

			while (previous_node && buffer)
			{
				previous_node = previous_node->prev;
				if (previous_node && previous_node->n < buffer->n)
				{
					previous_node->next->prev = buffer;
					buffer->next = previous_node->next;
					buffer->prev = previous_node;
					previous_node->next = buffer;
					previous_node = current_node->prev;
					buffer = NULL;
					print_list(*list);
				}
				if (previous_node == NULL)
				{
					buffer->next = *list;
					buffer->prev = NULL;
					*list = buffer;
					previous_node = current_node->prev;
					buffer = NULL;
					print_list(*list);
				}
			}
		}
	}
}
