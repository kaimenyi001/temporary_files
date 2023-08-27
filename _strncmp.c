#include "shell.h"

/**
 * _strncmp - compares two strings
 * @s1: string one
 * @s2: string two
 * @n: max number of characters to compare
 * Return: 0
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	else
		return (s1[i] - s2[i]);
}
