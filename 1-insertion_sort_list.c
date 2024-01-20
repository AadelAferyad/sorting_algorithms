#include "sort.h"

/**
 * insertion_sort_list - Insertion Sort is a simple sorting algorithm
 * that builds the final sorted array one element at a time.
 *
 * @list: head to the doubly linked list.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list, *inner_node, *tmp;
	int is_sorted = 0;

	while (node)
	{
		inner_node = node;
		while (inner_node && inner_node->prev)
		{
			if (inner_node->prev->n > inner_node->n)
			{
				is_sorted = 1;
				tmp = inner_node->prev;
				if (tmp->prev)
					tmp->prev->next = inner_node;
				inner_node->prev = tmp->prev;
				tmp->next = inner_node->next;
				if (inner_node->next)
					inner_node->next->prev = tmp;
				inner_node->next = tmp;
				tmp->prev = inner_node;
				if (!inner_node->prev)
					*list = inner_node;
				print_list(*list);
			}
			else if (!is_sorted)
				break;
			else
				inner_node = inner_node->prev;
		}
		node = node->next;
		is_sorted = 0;
	}
}
