#include "shell.h"

/**
  * _strdup - duplicates the string
  * @src: pointer to the source
  * Return: duplicated string
  */

char *_strdup(char *src)
{
	char *str;
	char *p;
	int len = 0;

	while (src[len])
		len++;
	str = malloc(len + 1);
	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}


/**
  * parse_string - parse the string receiveed from stdin
  * @buffer: string buffer
  * Return: parsed array
  */

char **parse_string(char *buffer)
{
	char *buffer_copy = NULL;
	char *token = NULL;
	char **argv = NULL;
	int argc = 0;
	int i;

	buffer_copy = _strdup(buffer);
	token = strtok(buffer, " \n");
	while (token)
	{
		token = strtok(NULL, " \n");
		argc++;
	}
	argv = malloc(argc * sizeof(char *));
	i = 0;
	token = strtok(buffer_copy, " \n");
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	return (argv);
}

