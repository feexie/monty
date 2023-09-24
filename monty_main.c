#include "monty.h"

/**
 * main - Entry point & Main program running byte ocde.
 * @argc: Number of arguments.
 * @argv: Argument in vector.
 * Return: Return exit success.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	m_buffer(argv[1]);
	return (EXIT_SUCCESS);
}

/**
 * opcode - operation code
 * @command: cammand input
 * @line_num: line number
 * @stack: stack of memory
 */
void opcode(char *command, unsigned int line_num, stack_t **stack)
{
	int y
	y = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
	};

	if (command[0] == '#')
	{
		return;
	}
	if (strcmp(command, "stack") == 0)
	{
		arg_holder.SQ = 1;
		return;
	}
	if (strcmp(command, "queue") == 0)
	{
		arg_holder.SQ = 0;
		return;
	}
	while (ops[y].opcode != NULL)
	{
		if (strcmp(ops[y].opcode, command) == 0)
		{
			ops[y].f(stack, line_num);
			return;
		}
		y++;
	}
	printf("L%d: unknown instruction %s\n", line_num, command);
	f_stack(stack);
	exit(EXIT_FAILURE);
}

#include "monty.h"
/**
 * f_stack - free the stack and the input
 * @head: input list pointer
 */
void f_stack(stack_t **head)
{
	stack_t *current;

	if (head == NULL)
		return;
	free(arg_holder.input_str);
	fclose(arg_holder.file);
	while (*head != NULL)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
}

/**
 * m_buffer - make the buffer and parse through the file
 * @file_name: name of the file
 */
void m_buffer(char *file_name)
{
	size_t size = 0;
	FILE *file_input;
	char *str = NULL;
	unsigned int linenum = 1;
	stack_t *stack = NULL;
	char *command = NULL;

	file_input = fopen(file_name, "r");
	if (file_input == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	arg_holder.file = file_input;
	arg_holder.SQ = 1;
	while (getline(&str, &size, file_input) != -1)
	{
		arg_holder.input_str = str;
		if (*str == '\n')
		{
			linenum++;
			continue;
		}
		command = strtok(str, "\n\t ");
		if (command == NULL)
		{
			linenum++;
			continue;
		}
		arg_holder.arg = strtok(NULL, "\n\t ");
		opcode(command, linenum, &stack);
		linenum++;
	}
	f_stack(&stack);
}
