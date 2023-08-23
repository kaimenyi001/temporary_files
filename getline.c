#include "shell.h"

/**
 * main - Entry point of the code
 * Return: 0
 */

int main(void)
{
	size_t buff_size;
	ssize_t ger;
	char *buff = NULL, *prompt = "$ ";
	bool piped = false;
	pid_t child;
	int stats;

	while (1 && !piped)
	{
		/*check if data is piped from the program or terminal*/
		if (isatty(STDIN_FILENO) == 0)
			piped = true;
		/* print prompt to the terminal*/
		write(STDOUT_FILENO, prompt, 2);
		/*Read data from input*/
		ger = getline(&buff, &buff_size, stdin);
		if (ger == -1)
		{
			perror("Error(getline error)");
			free(buff);
			exit(EXIT_FAILURE);
		}
		/*Replace newline char with a null terminator*/
		if (buff[ger - 1] == '\n')
			(buff[ger - 1] = '\0');
		/*create a child process*/
		int tkn_cnt;
		char *tokens[111];
		tkn_cnt = split_str(buff, tokens);

		if (tkn_cnt > 0)
		{
		child = fork();
		if (child == -1)
		{
			perror("Error(fork fails)");
			exit(EXIT_FAILURE);
		}
		if (child == 0)
		{
			char *execPath = search_exec(tokens[0], getenv("PATH"));

			if (execPath)
			{
				char *argv[] = {execPath, tokens[0], NULL};

				if (execve(execPath, argv, NULL) == -1)
				{
					perror("Error (execve failed)");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				perror("Command not found");
				exit(EXIT_FAILURE);
			}
		}
		if (waitpid(child, &stats, 0) == -1)
		{
			perror("Error(wait error)");
			exit(EXIT_FAILURE);
		}
		}
	}
	free(buff);
	return (0);
}
