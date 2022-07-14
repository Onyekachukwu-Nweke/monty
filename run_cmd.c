#include "monty.h"

/**
 * get_op_func - is a function pointer for list operations
 * done in the stack
 * @c: operator argument
 * Return: function pointer corresponding to operator given
 */

void (*get_op_func(void))(stack_t **head, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", pusher},
		{NULL, NULL}
	}

	int i = 0;

	while (ops[i].opcode != NULL && strcmp((ops[i].opcode), var.cmd) == 0)
		i++;
	return (ops[i].f);
}

/**
 * run_cmd - run the command
 * @bufline: line read from bytecode
 * Return: no return
 */
void run_cmd(char *bufline)
{
	void (*f)(stack_t **head, unsigned int line_number);

	var.cmd = strtok(bufline, DELIM);
	if (var.cmd && var.cmd[0] != '#')
	{
		f = get_op_func();
		if (f)
		{
			if (strcmp(var.cmd, "push") == 0)
				var.value = strtok(NULL, DELIM);
			f(&(var.head), var.line_number);
		}
		else
			/*Error*/
	}
}
