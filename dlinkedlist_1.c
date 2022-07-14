#include "monty.h"
#include "lists.h"

/**
 * print_dlistint - prints all the node in
 * a doubly linked list
 * @h: head pointer
 *
 * Return: number of nodes in the list or NULL.
 *
 */

size_t print_dlistint(const stack_t *h)
{
	size_t num;
	const stack_t *tmp = h;

	if (tmp == NULL)
		return (0);

	num = 0;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		num++;
		tmp = tmp->next;
	}

	return (num);
}

/**
 * add_dnodeint - function that add an
 * element at the beginning of the list
 *
 * @head: reference to head pointer
 * @n: data
 *
 * Return: address of new node or NULL.
 *
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = new_node;

	(*head) = new_node;

	return (*head);
}

/**
 * add_dnodeint_end - function that an
 * element at the end of a list
 *
 * @head: reference to the head pointer
 * @n: data
 *
 * Return: address of new element or NULL.
 *
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *end_node = (stack_t *)malloc(sizeof(stack_t));
	stack_t *last = *head;

	if (end_node == NULL)
	{
		free(end_node);
		return (NULL);
	}

	end_node->n = n;
	end_node->next = NULL;

	if ((*head) == NULL)
	{
		end_node->prev = NULL;
		(*head) = end_node;
		return (end_node);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = end_node;
	end_node->prev = last;
	return (end_node);
}
