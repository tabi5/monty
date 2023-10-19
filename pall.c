#include "monty.h"
/**
 * f_pall - function prints all the values on the stack,
 * starting from the top of the stack.
 * @head:  the double pointer to the head of the stack.
 * @counter: a current line number (not used in this function).
 * Return: does not return a value.
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *c_node;
	unsigned int l_number = counter;

	(void)l_number;

	c_node = *head;
	if (c_node == NULL)
		return;
	while (c_node)
	{
		printf("%d\n", c_node->n);
		c_node = c_node->next;
	}
}
