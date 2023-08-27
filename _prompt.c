#include "shell.h"

/**
 * _prompt - prints out prompt to th terminal
 * @prompt: what the prompt is
 * Return: void
 */

void _prompt(const char *prompt)
{
	write(STDOUT_FILENO, prompt, 0);
}
