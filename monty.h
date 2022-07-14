#ifndef MONTY_H
#define MONTY_H

/*Standard External Library*/
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>

/* Program Macros and Error */
#define DELIM " \r\t\n"
#define USAGE "USAGE: monty file\n"
#define NOACCESS "Error: Can't open file %s\n"
#define INVALID "L%d: unknown instruction %s\n"
#define MALLOC "Error: malloc failed\n"
#define PUSH "L%d: usage: push integer\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct global_s - global struct variables
 * @bufline: head of the stack
 * @value: value passed into the opcode
 * @line_number: line_number of the opcode
 * @fd: file descriptor
 * @op: command
 */

typedef struct global_s
{
	char *bufline;
	char *value;
	FILE *fd;
	stack_t *head;
	char *cmd;
	int mode;
	unsigned int line_number;
} global_t;

extern global_t var;

/*Program Functions*/
void init_var(void);
void error_hand(int code, ...);
void run_cmd(char *buf);
void free_buf(void);
void free_stack(void);
char *invstg(char *operand, unsigned int line_number);
void pusher(stack_t **head, unsigned int line_number);
void paller(stack_t **head, unsigned int line_number);
#endif /* End of Header File */
