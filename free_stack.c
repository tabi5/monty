#include "monty.h"

/**
 * free_stack - function frees a doubly linked list
 * It iterates through each node in the list and
 * deallocates the memory.
 * @head: This is the first parameter.
 */
void free_stack(stack_t *head)
{
	stack_t *curr_node;
	stack_t *nxt_node;

	curr_node = head;

	while (curr_node)
	{
		nxt_node = curr_node->next;
		free(curr_node);
		curr_node = nxt_node;
	}
}


