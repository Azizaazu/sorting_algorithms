#include "sort.h"

/**
 * _swap - Swaps two node
 *
 * @node: node base to change
 * @list: double link list head
 * Return: No Return
 *
 */

void _swap(listint_t **node, listint_t **list)
{
	listint_t *temp = *node, *temp2, *temp3;


	if (!(*node)->prev)
		*list = (*node)->next;

	temp = temp3 = *node;
	temp2 = temp->next;

	temp->next = temp2->next;
	temp3 = temp->prev;
	temp->prev = temp2;
	temp2->next = temp;
	temp2->prev = temp3;

	if (temp2->prev)
		temp2->prev->next = temp2;


	if (temp->next)
		temp->next->prev = temp;

	*node = temp2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: head of list to be sortered (Double Linked List)
 *
 * Return: No Return
 *
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *hd, *ax;
	int c = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	hd = *list;
	while (m >= n)
	{
		n++;
		while (hd->next && c != m)
		{
			if (hd->n > hd->next->n)
			{
				ax = hd;
			       _swap(&ax, list);
			       print_list(*list);
			       hd = ax;
			}

			c++;
			hd = hd->next;
		}

		if (n == 0)
			m = c;
		m--;
		while (hd->prev && c >= n)
		{
			if (hd->n < hd->prev->n)
			{
				ax = hd->prev;
				_swap(&ax, list);
				print_list(*list);
				hd = ax->next;
			}
			c--;
			hd = hd->prev;
		}
	}
}
