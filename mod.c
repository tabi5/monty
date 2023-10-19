#include "monty.h"

/**
 * f_mod - function computes the rest of the
 * division of the second top element
 *   of the stack by the top element of the stack.
 * @head: the double pointer to the head of the stack.
 * @counter: The current line number.
 * Return: no return
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *current_node, *nex_node;
	int sta_len = 0, res, no_val, next_node_val;

	current_node = *head;
	while (current_node)
	{
		current_node = current_node->next;
		sta_len++;
	}
	if (sta_len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	nex_node = current_node->next;
	no_val = current_node->n;
	next_node_val = nex_node->n;

	if (no_val == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	res = next_node_val % no_val;
	nex_node->n = res;
	*head = nex_node;
	free(current_node);
}

