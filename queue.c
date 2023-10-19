#include "monty.h"
/**
 * f_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	int queue_flag = 1;
	unsigned int line_num = counter;

	(void)head;
	(void)line_num;
	bus.lifi = queue_flag;
}

/**
 * addqueue - function Adds a new node to the end of
 * a doubly linked list.
 * @head: A double pointer to the head of the list.
 * @n: The integer to be added to the list.
 * This function creates a new node with 'n' as its data and
 * adds it to the end of a doubly linked list
 * pointed to by 'head'. If the
 * list is empty, the new node becomes
 * a first node. If memory allocation
 * fails, it prints an error message and returns.
 */
void addqueue(stack_t **head, int n)
{
	int n_value = n;
	stack_t *new_n, *aux_nod;
	int node_value = n;


	aux_nod = *head;
	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return;
	}
	new_n->n_value = node_value;
	new_n->next = NULL;
	if (aux_nod)
	{
		while (aux_nod->next)
			aux_nod = aux_nod->next;
	}
	if (!aux_nod)
	{
		*head = new_n;
		new_n->prev = NULL;
	}
	else
	{
		aux_nod->next = new_n;
		new_n->prev = aux_nod;
	}
}
