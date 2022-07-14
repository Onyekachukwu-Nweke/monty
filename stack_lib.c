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
		/*Error code 5*/

	i = 0;
	k = (strlen(operand));
	if (operand[0] == 45)
		i++;
	for (; i < k; i++)
	{
		if (operand[i] > 47 && operand[i] < 58)
			continue
		/*Error code 5*/
	}
	return (operand)
}

/**
 * pusher - function to push entered operand to stack
 * @head: The beginning of the linked list
 * @line_number: The line number of the opcode
 * Return: void
 */

void pusher(stack **head, unsigned int line_number)
{
	char *text;
	int n;

	text = invstg(var.value, line_number);
	n = atoi(text);
	if (var.mode == -1)
		add_dnodeint_end(stack, n);
	else
		add_dnodeint(stack, n);
}
