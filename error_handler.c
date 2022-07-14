#include "monty.h"
#include "lists.h"

/**
 * error_hand - this function handles errors
 * @code: error keycode
 * Return: void
 */

void error_hand(int code, ...)
{
	va_list param;
	int dig;
	char *par;

	va_start(param, code);
	switch (code)
	{
		case 1: /*Uasge Error*/
			dprintf(STDERR_FILENO, USAGE);
			break;
		case 2: /*File Access Error*/
			dprintf(STDERR_FILENO, NOACCESS, va_arg(param, char *));
			break;
		case 3: /*Invalid Opcode Error*/
			dig = va_arg(param, int);
			par = va_arg(param, char *);
			dprintf(STDERR_FILENO, INVALID, dig, par);
			break;
		case 4: /*Malloc Error*/
			dprintf(STDERR_FILENO, MALLOC);
			break;
		case 5: /*Push Error*/
			dprintf(STDERR_FILENO, PUSH, va_arg(param, int));
			break;
	}
}
