#include "monty.h"

/**
 * get_op_func - is a function pointer for list operations
 * done in the stack
 * Return: function pointer corresponding to operator given
 */

void (*get_op_func(void))(stack_t **head, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", pusher},
		{"pall", paller},
		{NULL, NULL}
	};

	int i = 0;

	for (; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, var.cmd) == 0)
			break;
	}

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
			error_hand(3, var.cmd, var.line_number), free_stack(); /*Free stack*/
	}
}
