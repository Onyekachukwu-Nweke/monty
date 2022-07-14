#ifndef LIST_H
#define LIST_H

stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
size_t print_dlistint(const stack_t *head);

#endif /*End of Header File*/
