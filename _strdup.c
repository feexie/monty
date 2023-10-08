#include "monty.h"

/**
* _strdup - duplicates a string
*
* @str: string to be duplicated
*
* Return: duplicated string.
*/
char *_strdup(const char *str)
{
size_t len;
char *new_str;

if (str == NULL)
{
return (NULL);
}

len = strlen(str) + 1;
new_str = malloc(len);

if (new_str != NULL)
{
memcpy(new_str, str, len);
}

return (new_str);
}
