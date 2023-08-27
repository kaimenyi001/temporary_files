#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>

extern char **environ;

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int split_str(char *input, char **tokens);
char *search_exec(char *cmd, char *path);
int _strlen(char *s);
void _prompt(const char *prompt);
void exec_cmd(char *tokens[]);
char *_input(size_t *buff_size);
void free_tokens(char *tokens[], int tkncnt);
char *_getenv(char *name, char **env);
int _strncmp(char *s1, char *s2, size_t n);

#endif
