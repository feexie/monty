#include "monty.h"

/**
* count_layers - counts the number of layers in a stack
*
* @stack: double pointer to the top (head) of the stack
*
* Return: number of layers found in a stack.
*/
int count_layers(stack_t **stack)
{
int layers = 0;
stack_t *head;

if (stack == NULL || *stack == NULL)
return (0);

head = *stack;
while (head)
{
layers++;
head = head->next;
}
return (layers);
}
