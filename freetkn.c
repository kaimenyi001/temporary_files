#include "shell.h"

/**
 * free_tokens - simply frees tokens
 * @tokens: words from splited string
 * @tkncnt: number of tokens
 * Return: void
 */

void free_tokens(char *tokens[], int tkncnt)
{
	int i;

	for (i = 0; i < tkncnt; i++)
	{
		free(tokens[i]);
	}
}
