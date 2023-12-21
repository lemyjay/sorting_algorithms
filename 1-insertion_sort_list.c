#include "sort.h"

/**
 * swap_nodes - Swaps two nodes when back->prev is not NULL
 *
 * @back: Pointer to the node to be swapped with the current node
 * @current: Pointer to the current node to be swapped
 * @front: Pointer to the node after the current node
 */
void swap_nodes(listint_t *back, listint_t *current, listint_t *front)
{
	if (front != NULL)
		front->prev = back;

	back->next = front;
	back->prev->next = current;
	current->prev = back->prev;
	current->next = back;
	back->prev = current;
}

/**
 * swap_head - Swaps two nodes when back->prev is NULL - when it hits the head
 * of the list
 *
 * @list: Pointer to the head of the list
 * @back: Pointer to the node to be swapped with the current node
 * @current: Pointer to the current node to be swapped
 * @front: Pointer to the node after the current node
 */
void swap_head(listint_t **list, listint_t *back,
	listint_t *current, listint_t *front)
{
	if (front != NULL)
		front->prev = back;

	back->next = front;
	back->prev = current;
	current->prev = NULL;
	current->next = back;
	*list = current;
}

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
				swap_nodes(back, current, front);
			else if (back->prev == NULL && current_value < back_value)
				swap_head(list, back, current, front);
			else
				break;

			print_list(*list);
		}

		current = temp->next;
	}
}
