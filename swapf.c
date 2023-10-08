#include "monty.h"

/**
* swapf - prints the element of the top layer.
*
* @stack: double pointer to the top of the stack.
* @line_number: the line number.
*
* Return: nothing
*/
void swapf(stack_t **stack, unsigned int line_number)
{
  stack_t *top_layer, *second_layer;
  int layers = count_layers(stack);

  if (layers < 2)
    {
      fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  top_layer = *stack;
  second_layer = top_layer->next;

  top_layer->prev = second_layer;
  second_layer->prev = NULL;

  top_layer->next = second_layer->next;
  second_layer->next = top_layer;
  *stack = second_layer;

}
