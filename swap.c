#include "monty.h"

/**
  * f_swap - the function Swaps the top two elements of the stack.
  * @head: the double pointer to the head of the stack.
  * @counter: a line number for error reporting
  * in case of usage errors.
  * the function swaps the top two elements of the stack.
  * If the stack contains less than two elements,
  * it prints an error message
  * and exits with a status of EXIT_FAILURE.
  * Return: the function function does not return a value.
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *temp_node;
	unsigned int line_number = counter;
	int stack_len = 0, temp_val;
	int swap_count = 0;

	temp_node = *head;
	while (temp_node)
	{
		temp_node = temp_node->next;
		stack_len++;
	}
	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp_node = *head;
	temp_val = temp_node->n;
	temp_node->n = temp_node->next->n;
	temp_node->next->n = temp_val;
	swap_count++;
	printf("Swap operation has been performed %d times.\n", swap_count);
}
