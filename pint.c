#include "monty.h"
/**
 * f_pint - prints the value at the top of the stack.
 * If the stack is empty, it prints an error message,
 * frees up memory, and exits.
 * @head: A double pointer to the head of the stack.
 * @counter: The current line number.
 * Return: function does not return a value.
*/
void f_pint(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	unsigned int line_num = counter;
	int top_value;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current_node = *head;
	top_value = current_node->n;
	printf("%d\n", top_value);
}
