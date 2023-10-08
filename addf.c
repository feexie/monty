#include "monty.h"

/**
* addf - adds the top 2 layers of a stack.
*
* @stack: double pointer to the top of the stack.
* @line_number: the line number.
*
* Return: nothing
*/
void addf(stack_t **stack, unsigned int line_number)
{
  stack_t *top_layer, *second_layer;
  int layers = count_layers(stack);

  if (layers < 2)
    {
      fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  top_layer = *stack;
  second_layer = top_layer->next;

  second_layer->n += top_layer->n;
  second_layer->prev = NULL;

  free(top_layer);
  *stack = second_layer;
}
