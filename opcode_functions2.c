#include "monty.h"

/**
 * fpush - Pushes an integer on the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number used to call push function.
 */

void fpush(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value_node;

	if (!args.value || isNotInteger(args.value) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		args.found_error = EXIT_FAILURE;
		return;
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		args.found_error = EXIT_FAILURE;
		return;
	}

	value_node = atoi(args.value);
	new_node->n = value_node;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * isNotInteger - checks is the str provides a digit
 * @str: string pointer parameter
 * Return: 1 if not a number and 0 if a number
*/

int isNotInteger(char *str)
{
	int status = 0, index = 0;

	while (str[index] != '\0')
	{
		if (str[index] == '-' || isdigit(str[index]))
		{
			index++;
			continue;
		}
		status = 1;
		break;
	}
	return (status);

}
