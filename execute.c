#include "monty.h"
/**
 * execute_opcode - executes opcodes
 * @stack: parameter
 * @line_number: line number parameter
 * Return: Void
 */
void execute_opcode(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instruction[] = {
		{"push", fpush}, {"pall", fpall},
		{"pint", fpint}, {"nop", NULL},
		{"swap", fswap}, {"pop", fpop},
		{"add", fadd}, {NULL, NULL}
		};

	if (!args.tokens || !args.tokens[0])
	return;
	while (instruction[i].opcode != NULL)
	{
		if (strcmp(instruction[i].opcode, args.tokens[0]) == 0)
		{
			if (strcmp(args.tokens[0], "push") == 0)
			{
				args.value = (args.tokens_count == 2 ? args.tokens[1] : NULL);
				instruction[i].f(stack, line_number);
			}
			else
			{
				if (instruction[i].f != NULL)
					instruction[i].f(stack, line_number);
			}
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d:unknown instruction %s\n", line_number, args.tokens[0]);
	args.found_error = EXIT_FAILURE;
}
