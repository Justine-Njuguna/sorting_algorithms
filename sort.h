#ifndef SORT_H
#define SORT_H

#include <stdlib.h>


/* Structs files */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prototypes for the files */

/* Prototypes for Print_list and print_array */
void print_list(const listint_t *list);

void print_array(const int *array, size_t size);

/* Task-0 */
void bubble_sort(int *array, size_t size);

/* Task-1 */
void insertion_sort_list(listint_t **list);

/* Task-2 */
void selection_sort(int *array, size_t size);

/* Task-3 */
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
