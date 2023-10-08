#include "monty.h"


/**
* free_stack - frees a stack
* @stack: top of the stack
*
* Return: nothing
*/
void free_stack(stack_t *stack)
{
stack_t *next;

while (stack != NULL)
{
next = stack->next;
free(stack);
stack = next;
}
}
