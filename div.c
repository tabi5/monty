#include "monty.h"
/**
 * f_div - the Function to divide the second top element
 * of the stack by the top element.
 * @head: a Double pointer to the head of the stack.
 * @counter: a line number for error reporting.
 *
 * Description: This function divides the second top
 * element of the stack by the top element,
 * removes the top element of the stack, and pushes
 *  the result onto the stack. If there are less than
 * two elements in the stack, or if division by zero
 * is attempted, it prints an error message and exits.
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *cur_node, *sec_node;
	int stk_length = 0, div_result;

	cur_node = *head;
	while (cur_node)
	{
		cur_node = cur_node->next;
		stk_length++;
	}
	if (stk_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	cur_node = *head;
	if (cur_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	sec_node = cur_node->next;
	div_result = sec_node->n / cur_node->n;
	sec_node->n = div_result;
	*head = sec_node;
	free(cur_node);
}

