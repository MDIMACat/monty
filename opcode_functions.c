#include "monty.h"

/**
 * fadd - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number used to call add function.
 */

void fadd(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		args.found_error = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * fpop - Removes the top element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number used to call the pop function.
 */

void fpop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		args.found_error = EXIT_FAILURE;
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

/**
 * fswap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number used to call the swap function.
 */


void fswap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		args.found_error = EXIT_FAILURE;
		return;
	}

	temp = (*stack)->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->prev = NULL;
	temp->next = *stack;
	*stack = temp;

}

/**
 * fpint - Prints the value the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number used to call pint function.
 */

void fpint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		args.found_error = EXIT_FAILURE;
		return;
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * fpall- Prints all the elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number used to call pall function.
 */

void fpall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (stack == NULL)
	{
		return;
	}
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
