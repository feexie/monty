#include "monty.h"

/**
* pallf - prints all of the element in a stack.
*
* @stack: double pointer to the top of the stack.
* @line_number: the line number.
*
* Return: nothing
*/
void pallf(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
int layers = count_layers(stack);
line_number = line_number;

if (layers == 0)
return;

tmp = *stack;
while (tmp)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}
