#include "shell.h"

/**
 * main - Entry point of the code
 * Return: 0
 */

int main(void)
{
	size_t buff_size;
	char *line, *buff = NULL, *prompt = "", *tokens[111];
	bool piped = false;
	int tkncnt;

	while (1 && !piped)
	{
		if (isatty(STDIN_FILENO) == 0)
			piped = true;

		_prompt(prompt);
		buff = _input(&buff_size);
		line = strtok(buff, "\n");

		while (line != NULL)
		{
			tkncnt = split_str(line, tokens);

			if (tkncnt > 0)
			{
				exec_cmd(tokens);
				free_tokens(tokens, tkncnt);
			}
			else if (tkncnt == -1)
			{
				free(buff);
				exit(EXIT_FAILURE);
			}

			line = strtok(NULL, "\n");
		}
		free(buff);
	}
	return (0);
}
