#include "monty.h"
/**
 * f_push - pushes an integer onto the stack
 * @stack_top: a double pointer to the top of the stack
 * @counter: the line number for error message
 * It checks if 'bus.arg'
 *(the argument to be pushed onto the stack) is not NULL.
 * If 'bus.arg' is not NULL, it checks if the
 *  argument is a negative number and then checks if all
 * characters in 'bus.arg' are digits.
 * If 'bus.arg' contains any non-digit characters,
 *it prints an error message, frees up allocated memory,
 *and exits the program.
 * If 'bus.arg' is NULL, it also prints an error message,
 *frees up allocated memory, and exits the program.
 * If 'bus.arg' passes these checks, it converts 'bus.arg'
 *to an integer and depending on the value of 'bus.lifi',
 * it either adds the new node to the top of
 *the stack or to the end of the queue.
 * Return: no return
*/
void f_push(stack_t **stack_top, unsigned int counter)
{
	int num_to_push, index = 0, is_not_num = 0;
	unsigned int line_number = counter;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			index++;
		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] > '9' || bus.arg[index] < '0')
				is_not_num = 1;
		}
		if (is_not_num == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack_top);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_top);
		exit(EXIT_FAILURE);
	}
	num_to_push = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(stack_top, num_to_push);
	else
		addqueue(stack_top, num_to_push);
}
