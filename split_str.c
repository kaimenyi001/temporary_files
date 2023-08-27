#include "shell.h"

/**
 * split_str - splits a string
 * @input: string from getline
 * @tokens: words after spliting
 * Return: tokencount
 */

int split_str(char *input, char **tokens)
{
	int i, tkncnt = 0;
	char *line, *token;

	line = strtok(input, "\n");
	while (line != NULL)
	{
		token = strtok(line, " ");
		while (token != NULL)
		{
			tokens[tkncnt] = _strdup(token);
			if (tokens[tkncnt] == NULL)
			{
				for (i = 0; i < tkncnt; i++)
				{
					free(tokens[i]);
				}
				return (-1);
			}
			tkncnt++;
			token = strtok(NULL, " ");
		}
		line = strtok(NULL, "\n");
	}

	tokens[tkncnt] = NULL;
	return (tkncnt);
}
