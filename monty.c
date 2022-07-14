#include "monty.h"

global_t var;

/**
 *
 *
 */

void init_var(void)
{
	var.head = NULL;
	var.bufline = NULL;
	var.op = NULL;
	var.value = NULL;
	var.line_number = 0;
	var.mode = 1;
}

/**
 *
 *
 */
int main(int ac, char **av)
{
	size_t size = 0;

	if (ac != 2)
	{
		/*Error*/
	}

	init_var();

	var.fd = fopen(av[1], "r");

	if (!var.fd)
		/*Error*/

	while (getline(&(var.bufline), &size, var.fd) != EOF)
	{
		var.line_number++;
		run_cmd(var.bufline);
	}
	/*Free both stack, var and line*/

	fclose(var.fd);
}
