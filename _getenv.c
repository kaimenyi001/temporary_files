#include "shell.h"

/**
 * _getenv - explore the path environment
 * @name: string
 * @env: the environ
 * Return: NULL
 */

char *_getenv(char *name, char **env)
{
	size_t _len = _strlen(name);
	char **env_var;

	for (env_var = env; *env_var != NULL; ++env_var)
	{
		if (_strncmp(*env_var, name, _len) == 0 && (*env_var)[_len] == '=')
		{
			return (&(*env_var)[_len + 1]);
		}
	}

	return (NULL);
}
