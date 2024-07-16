#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node2->next = node1;
	node1->prev = node2;

	print_list(*list);
}

/**
 * forward_pass - Perform a forward pass of cocktail shaker sort
 * @list: Double pointer to the head of the list
 * @start: Pointer to the starting node of the pass
 * @end: Pointer to the ending node of the pass
 *
 * Return: 1 if nodes were swapped, 0 otherwise
 */
int forward_pass(listint_t **list, listint_t *start, listint_t **end)
{
	int swapped = 0;
	listint_t *current = start;

	while (current->next != *end)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			swapped = 1;
		}
		else
		{
			current = current->next;
		}
	}
	*end = current;
	return (swapped);
}

/**
 * backward_pass - Perform a backward pass of cocktail shaker sort
 * @list: Double pointer to the head of the list
 * @start: Pointer to the starting node of the pass
 * @end: Pointer to the ending node of the pass
 *
 * Return: 1 if nodes were swapped, 0 otherwise
 */
int backward_pass(listint_t **list, listint_t **start, listint_t *end)
{
	int swapped = 0;
	listint_t *current = end;

	while (current && current->prev && current->prev != (*start)->prev)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			swapped = 1;
		}
		else
		{
			current = current->prev;
		}
	}
	*start = current->next;
	return (swapped);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = *list;
	listint_t *end = NULL;

	if (!list || !*list)
		return;

	do {
		swapped = forward_pass(list, start, &end);
		if (!swapped)
			break;
		swapped = backward_pass(list, &start, end);
	} while (swapped);
}
