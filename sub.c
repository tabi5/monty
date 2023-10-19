#include "monty.h"

/**
  * f_sub - Subtracts the top element of the stack
  * from the second top element.
  * @head: A double pointer to the head of the stack.
  * @counter: The line number for error reporting in case of usage errors.
  * This function subtracts the top element of the stack from
  * the second top element, removes the top element of the stack, and pushes
  * the result onto the stack. If the stack contains less than two elements,
  * it prints an error message and exits with a status of EXIT_FAILURE.
  *
  * Return: return function does not return a value.
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp_n;
	int diff, no_count;
	int sub_count = 0;
	unsigned int line_number = counter;

	temp_n = *head;
	for (no_count = 0; temp_n != NULL; no_count++)
		temp_n = temp_n->next;
	if (no_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp_n = *head;
	diff = temp_n->next->n - temp_n->n;
	temp_n->next->n = diff;
	*head = temp_n->next;
	free(temp_n);
	sub_count++;
	printf("Subtraction operation has been performed %d times.\n", sub_count);
}
