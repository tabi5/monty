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

	int i = 0;
	char *op = NULL;
	int retf = 0;
	instruction_t *instruction = NULL;


	op = strtok(content, " \n\t");
	if (op != NULL && op[0] == '#')
	{
		return (retf);
	}
	while (opst[i].opcode != NULL && op != NULL)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			instruction = &opst[i];
			break;
		}
		i++;
	}
	if (instruction == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	instruction->f(stack, counter);
	return (retf);
}

