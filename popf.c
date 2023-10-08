#include "monty.h"

/**
* popf - removes the top layer of the stack.
*
* @stack: double pointer to the top of the stack.
* @line_number: the line number.
*
* Return: nothing
*/
void popf(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp;
  int layers = count_layers(stack);

  if (layers == 0)
    {
      fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
      exit(EXIT_FAILURE);
    }
  tmp = *stack;
  *stack = tmp->next;
  free(tmp);
}
