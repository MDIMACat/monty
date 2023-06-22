#include "monty.h"

/**
 * tokenize_line-tokenizes the line
 * @str: string parameter
 * Return: tokenized line
*/

char **tokenize_line(char *str);
arg_t args = {NULL, NULL, NULL, NULL, 0, 0, 0, 0};

/**
 * main - main function
 * @argc: argument count parameter
 * @argv: argument vector parameter
 * Return: 1 of fail and 0 in success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char line[100];
	size_t len = 100;
	char *read;
	unsigned int line_number = 0;
	size_t line_length;

	check_command_line_arguments(argc, argv[1]);
	get_stream(argv[1]);
	while ((read = fgets(line, len, args.file)) != NULL)
	{
		if (args.found_error == 1)
			break;
		line_number++;
		line_length = strlen(line);
		if (line_length > 0 && line[line_length - 1] == '\n')
			line[line_length - 1] = '\0';
		args.line_number = line_number;
		args.tokens = tokenize_line(line);
		execute_opcode(&stack, line_number);
		free(args.tokens);
	}
	fclose(args.file);
	free_stack(stack);
	exit(args.found_error);
}

/**
 * get_stream - opens file
 * @filename: filename parameter
 * Return: Void
 */

void get_stream(const char *filename)
{
	args.file = fopen(filename, "r");
	if (args.file == NULL)
	{
		handle_file_open_error(filename);
	}
}
