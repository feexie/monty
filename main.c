#include "monty.h"

/**
* main - interpreter main function
*
* @ac: number of the command line arguments
* @av: double pointer to the command line arguments
*
* Return: 0 on success or exits with error message
*/
int main(int ac, char **av)
{
FILE *mbytefile;
char buffer[1024];
unsigned int line_number = 0;

if (ac != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

mbytefile = fopen(av[1], "r");
if (mbytefile == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", av[1]);
exit(EXIT_FAILURE);
}


while (fgets(buffer, 1024, mbytefile) != NULL)
{
execute(&line_number, buffer);
}

free_stack(stack);
fclose(mbytefile);

return (0);
}
