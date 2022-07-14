#include "monty.h"
#include "lists.h"

/**
 * free_buf - free the global struct variable
 */
void free_buf(void)
{
	if (var.bufline)
		free(var.bufline);
}

/**
 * free_stack - free the created stack
 */
void free_stack(void)
{
	if (var.head)
		free_dlistint(var.head);
}
