#include "monty.h"

/**
* pushf - adds a layer to stack.
*
* @stack: double pointer to the top of the stack.
* @line_number: the line number.
*
* Return: nothing
*/
void pushf(stack_t **stack, unsigned int line_number)
{
stack_t *new;
int i;
int number;

if (item == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
if (item[0] == '-')
i = 1;
else
i = 0;
while (item[i] != '\0')
{
if (!isdigit(item[i]))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
i++;
}
number = atoi(item);
new = malloc(sizeof(stack_t));
if (new == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new->n = number;
new->prev = NULL;
new->next = *stack;
*stack = new;

if (new->next != NULL)
(new->next)->prev = new;
}
