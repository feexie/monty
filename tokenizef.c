#include "monty.h"

/**
* tokenizef - Tokenize a string into simple tokens usimg space as delimeter.
*
* @line: Pointer to the string to be tokenized.
* Return: An array of pointers representing the command tokens.
*/
char **tokenizef(char **line)
{
char *tokena;
char *tokenb;
char *linecp = _strdup(*line);
char **command = NULL;
int i;

if (line == NULL)
return (NULL);

tokena = strtok(*line, " ");
for (i = 0; tokena != NULL; i++)
tokena = strtok(NULL, " ");


command = malloc((i + 1) * sizeof(char *));
tokenb = strtok(linecp, " ");
for (i = 0; tokenb != NULL; i++)
{
command[i] = _strdup(tokenb);
tokenb = strtok(NULL, " ");
}

command[i] = NULL;
free(linecp);

return (command);
}
