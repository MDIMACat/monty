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

	if (!args.value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		args.found_error = EXIT_FAILURE;
		return;
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Malloc failed\n");
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

