#include "monty.h"
#include "lists.h"

/**
 * invstg - a function that investigates if the operand is numeric
 * @operand: the operand to investigate
 * @line_number: The line number the opcode is being worked on
 * Return: the operand
 */

char *invstg(char *operand, unsigned int line_number)
{
	int i, k;

	if (operand == NULL)
		error_hand(5, line_number);

	i = 0;
	k = (strlen(operand));
	if (operand[0] == 45)
		i++;
	for (; i < k; i++)
	{
		if (operand[i] > 47 && operand[i] < 58)
			continue;
		error_hand(5, line_number);
		exit(EXIT_FAILURE);
	}
	return (operand);
}

/**
 * pusher - function to push entered operand to stack
 * @head: The beginning of the linked list
 * @line_number: The line number of the opcode
 * Return: void
 */

void pusher(stack_t **head, unsigned int line_number)
{
	char *text;
	int n;

	text = invstg(var.value, line_number);
	n = atoi(text);
	add_dnodeint(head, n);
}

/**
 * paller - prints all the elements in the list
 * @head: reference head node
 * @line_number: line_number
 */
void paller(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*head);
}

/**
 *
 *
 */
void pinter(stack_t **head, unsigned int line_number)
{
	stack_t *start = *head;

	if (!start)
		error_hand(6, line_number);

	printf("%d\n", start->n);
}
