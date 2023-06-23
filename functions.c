#include "monty.h"

/**
 * tokenize_line - tokenize line
 * @str: string parameter
 * Return: tokens
 */

char **tokenize_line(char *str)
{
	char *token = NULL;
	int i = 0;
	char **con_tokens = NULL;
	char *delim = " \n\t\r";

	con_tokens = malloc(sizeof(char *) * 3);
	if (con_tokens == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		args.found_error = EXIT_FAILURE;
		return (NULL);
	}
	token = strtok(str, delim);
	while (token != NULL && i < 2)
	{
		con_tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	con_tokens[i] = NULL;
	args.tokens_count = i;
	return (con_tokens);
}

/**
 * handle_file_open_error - handle error
 * @filename: argv parameter
 * Return: Void
 */

void handle_file_open_error(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * check_command_line_arguments - checks command line args
 * @argc: count parameter
 * @filename: filename parameter
 * Return: void
 */

void check_command_line_arguments(int argc, char *filename)
{
	const char *extension;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	extension = strrchr(filename, '.');
	if (extension == NULL || strcmp(extension, ".m") != 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
