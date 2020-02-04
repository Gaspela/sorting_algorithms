#include "sort.h"
/**
 * insertion_sort_list - Sort.
 * @list: Double link list
*/
void insertion_sort_list(listint_t **list)
{
	
	listint_t *tmpnext = NULL;

        if (*list == NULL || !list)
                return;
	
	tmpnext = (*list)->next;
	while (tmpnext != NULL)
	{
		while (tmpnext->prev != NULL && tmpnext->n < tmpnext->prev->n)
		{
			tmpnext->prev->next = tmpnext->next;

			if (tmpnext->next != NULL)
				tmpnext->next->prev = tmpnext->prev;
			
			tmpnext->next = tmpnext->prev;
			tmpnext->prev = tmpnext->prev->prev;
			tmpnext->next->prev = tmpnext;
			
			if (tmpnext->prev == NULL)
				*list = tmpnext;
			else
				tmpnext->prev->next = tmpnext;
			print_list(*list);
		}
		tmpnext = tmpnext->next;
	}
}
