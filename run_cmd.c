#include "monty.h"

/**
 * get_op_func - is a function pointer for list operations
 * done in the stack
 * @c: operator argument
 * Return: function pointer corresponding to operator given
 */

void (*get_op_func(char *c))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{NULL, NULL}
	}

	int i = 0;

	while (ops[i].opcode != NULL && strcmp((ops[i].opcode), s)
			i++;
	return (ops[i].f);
}
