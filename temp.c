#include "sort.h"

/**
 * insertion_sort_list -  A function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 *
 * @list: a pointer that points to the pointer of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current =  NULL, *temp = NULL, *front = NULL, *back = NULL;
	int current_value, back_value;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		while (1)
		{
			front = current->next;
			back = current->prev;
			current_value = current->n;
			if (back != NULL)
				back_value = current->prev->n;
			else
				break;
			if (back->prev != NULL && current_value < back_value)
			{
				(front != NULL) ? (front->prev = back) : 0;
				back->next = front;
				back->prev->next = current;
				current->prev = back->prev;
				current->next = back;
				back->prev = current;
			}
			else if (back->prev == NULL && current_value < back_value)
			{
				(front != NULL) ? (front->prev = back) : 0;
				back->next = front;
				back->prev = current;
				current->prev = NULL;
				current->next = back;
				*list = current;
			}
			else
				break;
			print_list(*list);
		}
		current = temp->next;
	}
}
