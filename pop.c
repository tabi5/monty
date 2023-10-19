#include "monty.h"
/**
 * f_pop - pops an element from the top of the stack
 *This function pops an element from the top of the stack.
 * If the stack is empty, it prints an error message,
 * frees up allocated memory,
 * and exits the program. If the stack is not empty,
 * it removes the top element
 * from the stack and adjusts the head pointer to
 * point to the next node.
 * @head: double pointer to the head of the stack
 * @counter: line number for error message
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;
	stack_t *nex_node;
	unsigned int line_number = counter;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	nex_node = h->next;
	*head = nex_node;
	free(h);
}
