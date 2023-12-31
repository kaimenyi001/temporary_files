#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename
 * @text_content: content in the file
 * Return: 1 if it success. -1 if it fails
 */

int create_file(const char *filename, char *text_content)
{
	int i, j, k;

	if (!filename)
		return (-1);

	i = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (i == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (j = 0; text_content[j]; j++)
		;

	k = write(i, text_content, j);

	if (k == -1)
		return (-1);

	close(i);

	return (1);
}
