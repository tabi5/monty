#include "monty.h"
/**
 *f_nop- function does nothing. It's often used
 *to handle cases where an operation is required
 *for type compatibility, but no action needs to be performed.
 *@head:  A double pointer to the head of the stack.
 *@counter:the current line number.
 *Return: does not return a value.
 */
void f_nop(stack_t **head, unsigned int counter)
{
	stack_t *cur_node = *head;
	unsigned int l_number = counter;

	(void) l_number;
	(void) cur_node;
}
