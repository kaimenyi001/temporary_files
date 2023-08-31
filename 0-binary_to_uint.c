#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointing to a string
 * Return: converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0;
	int j, k;

	if (!b)
		return (0);
	for (j = 0; b[j] != '\0'; j++)
		;
	for (j--, k = 1; j >= 0; j--, k *= 2)
	{
		if (b[j] != '0' && b[j] != '1')
		{
			return (0);
		}

		if (b[j] & 1)
		{
			i += k;
		}
	}
	return (i);
}
