#include "monty.h"
/**
 * execute - the Function to parse and execute
 * instructions from a scripting language.
 * @content: the pointer to a character. This is the string
 * containing the instructions to be executed.
 * @stack: the double pointer to a stack_t structure.
 * This is the stack on which the instructions operate.
 * @counter: An unsigned integer. This is used for error reporting,
 *  it represents the line number of the instruction.
 * @file: the pointer to a FILE. This is the file from which
 * the instructions are read.
 * Return: return 0 if an opcode starting with '#' is found
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t varopst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"queue", f_queue},
		{"stack", f_stack},
		{NULL, NULL}
	};
	unsigned int l = 0;
	int vreturn = 0;
	char *varop;

	varop = strtok(content, " \n\t");
	if (varop && varop[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (varopst[l].opcode && varop)
	{
		if (strcmp(varop, varopst[l].opcode) == 0)
		{	varopst[l].f(stack, counter);
			return (vreturn);
		}
		l++;
	}
	if (varop && varopst[l].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, varop);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

