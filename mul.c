#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: A double pointer to the head of the stack.
 * @counter: The current line number.
 * Return: This function does not return a value.
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *curr_node, *ne_node;
	int stack_l = 0, product, node_val, next_node_value;

	curr_node = *head;
	while (curr_node)
	{
		curr_node = curr_node->next;
		stack_l++;
	}
	if (stack_l < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	curr_node = *head;
	ne_node = curr_node->next;
	node_val = curr_node->n;
	next_node_value = ne_node->n;

	product = next_node_value * node_val;
	ne_node->n = product;
	*head = ne_node;
	free(curr_node);
}

