#include "shell.h"

/**
  * parse_string - parse the string receiveed from stdin
  * @buffer: string buffer
  * Return: parsed array
  */

char **parse_string(char *buffer)
{
	char *token;
	char **argv;
	int argc = 0;
	int i;

	token = strtok(buffer, " \n");
	while (token)
	{
		token = strtok(NULL, " \n");
		argc++;
	}
	argv = malloc(argc * sizeof(char *));
	i = 0;
	token = strtok(buffer, " \n");
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

