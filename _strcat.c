#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: string one
 * @src: string two
 * Return: void
 */

char *_strcat(char *dest, char *src)
{
	int m = 0, n = 0;

	while (dest[m] != '\0')
	{
		m++;
	}
	while (src[n] != '\0')
	{
		dest[m] = src[n];
		m++;
		n++;
	}
	dest[m] = '\0';
	return (dest);
}
