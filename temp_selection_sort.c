#include "sort.h"

/**
 * insertion_sort_list -  A function that sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 *
 * @list: a pointer that points to the pointer of the list
 */
void insertion_sort_list(listint_t **list)
{
	 listint_t *current =  NULL, *temp_l = NULL, *temp_k = NULL;
        int temp;
	int *value;

        if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;

        current = *list;
        while (current != NULL)
        {
                temp = current->n;
                temp_l = current;
                temp_k = NULL;
                while (temp_l != NULL)
                {
                        if (temp_l->n < temp)
                        {
                                temp_k = temp_l;
                                temp = temp_l->n;
                        }
                        temp_l = temp_l->next;
                }
		if (temp_k != NULL)
		{
			int swap = current->n;

			value = NULL;
			value = (int *)&current->n;
			*value = temp;
			value = (int *)&temp_k->n;
			*value = swap;
		}
		print_list(*list);
		current = current->next;
        }
}
