#include "monty.h"
/**
 * addnode - Function to add a new node to the stack
 * @head: a Double pointer to the head of the stack
 * @n: a integer value to be added to the new node
 *
 * Description: it creates a new node with the given integer value,
 * and adds it to a top of the stack pointed to by head.
 *  If memory allocation
 * fails, it prints an error message and exits.
 */
void addnode(stack_t **head, int n)
{
	stack_t *n_node, *cur_head;
	int node_val;

	cur_head = *head;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	node_val = n;
	if (cur_head)
		cur_head->prev = n_node;
	n_node->n = node_val;
	n_node->next = cur_head;
	n_node->prev = NULL;
	*head = n_node;
}

