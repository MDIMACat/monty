#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: parameter
 * Return: Void
 */
void free_stack(stack_t *stack)
{
	stack_t *current;
	stack_t *next;

	if (stack == NULL)
	{
		return;
	}
	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
