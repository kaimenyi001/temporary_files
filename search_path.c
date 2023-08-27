#include "shell.h"
#define MAX_PATH 100

/**
 * search_exec - finds the executable path in the 'PATH'
 * @cmd: the command
 * @path: the executable path inputed
 * Return: null
 */

char *search_exec(char *cmd, char *path)
{
	char *drcs[MAX_PATH];
	int i, dirCnt = 0;
	char execPath[777], *token, *path_cpy;

	path_cpy = _strdup(path);
	token = strtok(path_cpy, ":");

	while (token != NULL && dirCnt < MAX_PATH)
	{
		drcs[dirCnt++] = token;
		token = strtok(NULL, ":");
	}
	free(path_cpy);

	for (i = 0; i < dirCnt; i++)
	{
		_strcpy(execPath, drcs[i]);
		_strcat(execPath, "/");
		_strcat(execPath, cmd);

		if (access(execPath, X_OK) == 0)
		{
			return (_strdup(execPath));
		}
	}
	return (NULL);
}
