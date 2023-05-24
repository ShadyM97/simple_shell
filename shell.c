#include "shell.h"

/**
  * shell - This is a function that runs the shell
  */

void shell(void)
{
	char *buffer = NULL;
	size_t bufsize = 32;
	char **argv;
	int argc = 0;
	pid_t pid;

	while (1)
	{
		pid = fork();
		if (pid == -1)
			perror("Error:");
		else if (pid == 0)
		{
			printf("$ ");
			getline(&buffer, &bufsize, stdin);
			argv = parse_string(buffer);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			exit(0);
		}
		else
			wait(NULL);
	}
	free(buffer);
}
