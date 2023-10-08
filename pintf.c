#include "monty.h"

/**
* pintf - prints the element of the top layer.
*
* @stack: double pointer to the top of the stack.
* @line_number: the line number.
*
* Return: nothing
*/
void pintf(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp;
  int layers = count_layers(stack);

  if (layers == 0)
    {
      fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }
  tmp = *stack;
  printf("%d\n", tmp->n);
}
