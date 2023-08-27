#include "shell.h"

/**
 * _strlen - writes the len of a string
 * @s: input string
 * Return: length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;
	return (len);
}
