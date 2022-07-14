#include "monty.h"

global_t var;

/**
 * init_var - initializes the variables
 */

void init_var(void)
{
	var.head = NULL;
	var.bufline = NULL;
	var.cmd = NULL;
	var.value = NULL;
	var.line_number = 0;
	var.mode = 1;
}

/**
 * main - the entry point function in the
 * interpreter
 * @ac: argument counter
 * @av: argument value
 * Return: EXIT_SUCCESS
 */
int main(int ac, char **av)
{
	size_t size = 0;

	if (ac != 2)
		error_hand(1);

	init_var();

	var.fd = fopen(av[1], "r");

	if (!var.fd)
		error_hand(2, av[1]);

	while (getline(&var.bufline, &size, var.fd) != EOF)
	{
		var.line_number++;
		run_cmd(var.bufline);
	}
	/*Free both stack, var and line*/
	free_buf(), free_stack();
	fclose(var.fd);

	return (EXIT_SUCCESS);
}
