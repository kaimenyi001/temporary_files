#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: filename
 * @letters: numbers of letter it should read and print
 * Return: numbers of letters printed. It fails, returns 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int i;
	ssize_t j, k;
	char *c;

	if (!filename)
		return (0);

	i = open(filename, O_RDONLY);

	if (i == -1)
		return (0);

	c = malloc(sizeof(char) * (letters));
	if (!c)
		return (0);

	j = read(i, c, letters);
	k = write(STDOUT_FILENO, c, j);

	close(i);

	free(c);

	return (k);
}
