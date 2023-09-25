#include "sort.h"
#include <stdio.h>


/**
 * insertion_sort_list - sorts a DLL of integers
 *
 * @list: doubly linked list
 * Return: no return
 *
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *p, *temp;

	if (!list)
		return;

	p = *list;

	while (p)
	{
		while (p->next && (p->n > p->next->n))
		{
			temp = p->next;
			p->next = temp->next;
			temp->prev = p->prev;

			if (p->prev)
				p->prev->next = temp;

			if (temp->next)
				temp->next->prev = p;

			p->prev = temp;
			temp->next = p;

			if (temp->prev)
				p = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
		p = p->next;
	}
}
