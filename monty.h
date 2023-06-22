#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct arg_s - global variable struct
 * @file: pointer member
 * @tokens: pointer member
 * @value: pointer member
 * @line: pointer member
 * @line_number: line number member
 * @tokens_count: tokens count member
 * @found_error: find error member
 *
 * Description: Struct defined to at as a global variable
*/
typedef struct arg_s
{
	FILE *file;
	char **tokens;
	char *value;
	char *line;
	unsigned int line_number;
	int tokens_count;
	int found_error;
} arg_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes*/
void get_stream(const char *filename);
void execute_opcode(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void handle_file_open_error(const char *filename);
void check_command_line_arguments(int argc, char *filename);
void fpush(stack_t **stack, unsigned int line_number);
void fpall(stack_t **stack, unsigned int line_number);
void fpint(stack_t **stack, unsigned int line_number);
void fswap(stack_t **stack, unsigned int line_number);
void fpop(stack_t **stack, unsigned int line_number);
void fadd(stack_t **stack, unsigned int line_number);
void fnop(stack_t **stack, unsigned int line_number);
extern arg_t args;

#endif
