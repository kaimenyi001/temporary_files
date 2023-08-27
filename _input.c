#include "shell.h"

/**
 * _input - reads input from getline
 * @buff_size: buffer size
 * Return: buffer
 */

char *_input(size_t *buff_size)
{
	ssize_t ger;
	char *buff = NULL;

	ger = getline(&buff, buff_size, stdin);
	if (ger == -1)
	{
		perror("Error(getline error)");
		free(buff);
		exit(EXIT_FAILURE);
	}

	while (*buff == ' ')
		buff++;


	return (buff);
}
