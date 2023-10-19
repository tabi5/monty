#include "monty.h"

/**
  * f_stack - Sets the format of the data to a stack (LIFO).
  * @head: A double pointer to the head of the stack.
  * @counter: The line number for error reporting in case of usage errors.
  *
  * Description: This function sets the format of the data to a stack (LIFO).
  * It does nothing with the stack itself, but changes a global variable
  * 'lifo' in the 'bus' struct to 0, indicating that the data should be
  * treated as a stack.
  *
  * Return: This function does not return a value.
 */
void f_stack(stack_t **head, unsigned int counter)
{
	int call_count = 0;
	unsigned int line_number = counter;

	(void)head;
	(void)line_number;
	bus.lifo = 0;
	call_count++;
	printf("f_stack function has been called %d times.\n", call_count);
}
