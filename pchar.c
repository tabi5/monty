#include "monty.h"
/**
 * f_pchar - function prints the char at the top of the stack,
 * starting from the top of the stack.
 *   The integer stored at the top of the stack is treated as
 * an ASCII value in the range 0 through 127.
 *   If the stack is empty, or if the integer is not in ASCII range,
 * it prints an error message, frees up memory, and exits.
 * @head: stack head
 * @counter:  a current line number.
 * Return: does not return a value.
*/
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *current_n;
	unsigned int lnumber = counter;
	int valascii_value;

	current_n = *head;
	if (!current_n)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lnumber);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	valascii_value = current_n->n;
	if (valascii_value > 127 || valascii_value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lnumber);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", valascii_value);
}
