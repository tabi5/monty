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
	stack_t *new_node, *aux;
	int new_var;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_var = n;
	new_node->n = new_var;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
