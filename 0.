#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @line_num: Line number.
 */
void push(stack_t **stack, unsigned int line_num)
{
	char *arg = arg_holder.arg;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (!isnum(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/* Create a new stack element */
	stack_t *new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(arg);
	new->prev = NULL;

	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}

	*stack = new;
}

/**
 * pall - Prints all values on the stack.
 * @stack: Pointer to the stack.
 * @line_num: Line number.
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	(void)line_num;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

