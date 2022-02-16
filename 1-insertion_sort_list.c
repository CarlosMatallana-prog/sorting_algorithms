#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Pointer to head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *previous = NULL, *saved = NULL;

	if (list)
	{
		previous = *list;
		current = previous->next;
		while (current)
		{
			saved = previous;
			if (current->n < previous->n)
			{
				saved = previous;
				while (previous && previous->n > current->n)
				{
					previous->next = current->next;
					if (current->next)
						current->next->prev = previous;
					previous = previous->prev;
					if (previous)
					{
						current->next = previous->next;
						previous->next = current;
						current->prev = previous;
					}
					else
					{
						current->next = *list;
						current->prev = NULL;
						*list = current;
					}
					if (current->next)
						current->next->prev = current;
					print_list(*list);
				}
				current = saved, previous = current->prev;
			}
			current = current->next, previous = previous->next;
		}
	}
}
