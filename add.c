#include "monty.h"
/**
 * f_add - Adds the top two elements of the stack.
 * @head: the double pointer to the head of the stack.
 * @counter: a line number for error reporting.
 * Description: This function takes a double pointer to the head of a stack
 * and a line number. It adds the top two elements of the stack and stores
 * the result in the second topmost element, then removes the top element.
 * If there are fewer than two elements in the stack,
 * it prints an error message,
 * frees memory, and exits.
 * Return: No return value.
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *cur_node, *sec_node;
	int stack_length = 0, sum;

	cur_node = *head;
	while (cur_node)
	{
		cur_node = cur_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	cur_node = *head;
	sec_node = cur_node->next;
	sum = cur_node->n + sec_node->n;
	sec_node->n = sum;
	*head = sec_node;
	free(cur_node);
}


