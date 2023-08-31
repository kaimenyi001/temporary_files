#include "main.h"

/**
 * get_endianness - checks the endianness
 * Return: void
 */

int get_endianness(void)
{
	unsigned int i;
	char *c;

	i = 1;
	c = (char *) &i;
	return ((int)*c);
}
