#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	pid_t pid = fork();
	if (pid == 0) // Child
	{
		// Making array to store child processes
		char **args_chld = malloc(argc * sizeof(char *));
		for (int i = 0; i < argc - 1; i++)
		{
			args_chld[i] = malloc(strlen(argv[i + 1]) * sizeof(char));
			strcpy(args_chld[i], argv[i + 1]);
		}
		args_chld[argc - 1] = NULL;

		execvp(args_chld[0], args_chld);

		for (int i = 0; i < argc - 1; i++)
			free(args_chld[i]);
		free(args_chld);
	}
	else if (pid > 0) // Parent
	{
		wait(NULL);
	}
	else
	{
		printf("err\n");
	}
	return 0;
}
