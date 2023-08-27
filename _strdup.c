#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string
 * Return: void
 */

char *_strdup(char *str)
{
	char *out;
	size_t len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;
	out = malloc(len);

	if (out == NULL)
		return (NULL);

	_strcpy(out, str);
	return (out);
}
