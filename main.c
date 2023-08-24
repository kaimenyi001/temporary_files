#include "shell.h"

/**
 * main - Entry point of the code
 * Return: 0
 */

int main(void)
{
	size_t buff_size;
	ssize_t ger;
	char *buff = NULL, *prompt = "", *tokens[111];
	bool piped = false;
	pid_t child;
	int stats, tkncnt, i;
	
	while (1 && !piped)
	{
		if (isatty(STDIN_FILENO) == 0)
			piped = true;
		write(STDOUT_FILENO, prompt, 0);
		ger = getline(&buff, &buff_size, stdin);
		if (ger == -1)
		{
			perror("Error(getline error)");
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (buff[ger - 1] == '\n')
			(buff[ger - 1] = '\0');
		tkncnt = split_str(buff, tokens);
		if (tkncnt > 0)
		{
			child = fork();
			if (child == -1)
			{
				perror("Error(fork fails)");
				free(buff);
				exit(EXIT_FAILURE);
			}
			if (child == 0)
			{
				if (execve(tokens[0], tokens, NULL) == -1)
				{
					perror("./shell");
					free(buff);
					exit(EXIT_FAILURE);
				}
			}
			if (waitpid(child, &stats, 0) == -1)
			{
				perror("Error(wait error)");
				free(buff);
				exit(EXIT_FAILURE);
			}
		}
		for (i = 0; i < tkncnt; i++)
			free(tokens[i]);
	}
	free(buff);
	return (0);
}
