#include "monty.h"
/**
 * f_pstr - prints the string starting at the top of the stack
 * @stack_top: a double pointer to the top of the stack
 * @line_number: the line number for error message
 * It treats each integer in the stack as
 * an ASCII value and prints the corresponding character.
 * It stops printing when it encounters
 * a node with an integer that is not
 * within the ASCII printable character range (1 to 127) or
 * when it reaches the end of the stack.
 * After printing all characters, it prints a new line.
 * Return: no return
*/
void f_pstr(stack_t **stack_top, unsigned int line_number)
{
	stack_t *curr_node;
	int valascii_value;
	unsigned int linenu = line_number;
	(void)linenu;

	curr_node = *stack_top;
	while (curr_node)
	{
		valascii_value = curr_node->n;
		if (valascii_value > 127 || valascii_value <= 0)
		{
			break;
		}
		printf("%c", valascii_value);
		curr_node = curr_node->next;
	}
	printf("\n");
}
