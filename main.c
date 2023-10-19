#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - the function serves as an interpreter
 * for Monty bytecodes.
 * @argc: a number of arguments passed to the program.
 * @argv: An array of strings representing the
 * arguments passed to the program.
 * It starts by checking if the correct number
 * of arguments has been passed.
 * If not, it prints an error message and exits.
 * Next, it attempts to open a file
 * specified by the user. If the file cannot be opened,
 * it prints an error message and exits.
 * The function then enters a loop where it reads lines
 * from the file one by one using the getline function.
 * For each line, it calls the execute function,
 *  passing in the content of the line,
 * a pointer to the stack, the line number,
 * and the file pointer. After all lines have been read and executed,
 * it frees any remaining memory and closes the file before
 *  returning 0 to indicate successful execution.
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *line_content;
	int var_zero = 0;
	FILE *monty_file;
	size_t buffer_size = 0;
	ssize_t is_line_read = 1;
	stack_t *stack_data = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	bus.file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (is_line_read > var_zero)
	{
		line_content = NULL;
		is_line_read = getline(&line_content, &buffer_size, monty_file);
		bus.content = line_content;
		line_counter++;
		if (is_line_read > var_zero)
		{
			execute(line_content, &stack_data, line_counter, monty_file);
		}
		free(line_content);
	}
	free_stack(stack_data);
	fclose(monty_file);
	return (var_zero);
}

