#include "monty.h"

char *item = NULL;
stack_t *stack = NULL;

/**
* execute - takes an instrucntion and finds
* the needed function to execute it
*
* @line_number: pointer to the line number
* @line: line of the byteCode file.
*
* Return: nothing
*/
void execute(unsigned int *line_number, char *line)
{
int i = 0;
char **command = NULL;
instruction_t instructions[] = {
{"push", pushf},
{"pall", pallf},
{"pint", pintf},
{"pop", popf},
{"swap", swapf},
{"add", addf},
{"nop", nopf},
{NULL, NULL},
};

*line_number += 1;
stripf(line);
if (strlen(line) == 0)
return;

command = tokenizef(&line);
while (instructions[i].opcode)
{
if (strcmp(command[0], instructions[i].opcode) == 0)
{
item = command[1];
instructions[i].f(&stack, *line_number);
free_command(command);
return;
}
i++;
}

free_command(command);
fprintf(stderr, "L%u: unknown instruction %s\n", *line_number, command[0]);
exit(EXIT_FAILURE);

}
