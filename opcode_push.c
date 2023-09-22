#include "monty.h"

/**
 * isnum - Check if a string is a number.
 * @str: String input.
 * Return: 1 if true, 0 if false.
 */
int isnum(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * _stack - Push a new element onto the stack (LIFO).
 * @stack: Pointer to the stack.
 * @new: New stack element to add.
 */
void _stack(stack_t **stack, stack_t *new)
{
	new->n = atoi(arg_holder.arg);
	new->prev = NULL;

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}

	*stack = new;
}

/**
 * _queue - Enqueue a new element (FIFO).
 * @stack: Pointer to the stack.
 * @new: New stack element to add.
 */
void _queue(stack_t **stack, stack_t *new)
{
	new->n = atoi(arg_holder.arg);
	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		stack_t *current = *stack;
		while (current->next != NULL)
			current = current->next;

		current->next = new;
		new->prev = current;
	}
}

/**
 * push - Push integers onto the stack or enqueue, based on mode.
 * @stack: Pointer to the stack.
 * @line_num: Line number.
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	if (!isnum(arg_holder.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (arg_holder.SQ)
		_stack(stack, new);
	else
		_queue(stack, new);
}

