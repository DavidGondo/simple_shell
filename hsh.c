#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

/**
*main: entry to program
*
*startDisplay - first prompt
*
*displayPrompt - prompt to display when program starts
*
*makeTokens - tokenixning the line
*
*execute -executing the program
*
*Return - 0 if success
*
*/

void startDisplay(void)
{
	printf("**************************************************************\n");
	printf("*WELCOME TO THE COMMAND LINE INTERPETER                      *\n");
	printf("*TO RUN A COMMAND SIMPLY TYPE YOUR COMMAND AND PRESS 'ENTER' *\n");
	printf("*EXAMPLE: ls -a                                              *\n");
	printf("*TO EXIT TYPE 'q'                                            *\n");
	printf("**************************************************************\n");
}

void displayPrompt(void)
{
	printf("$");
}

void makeTokens(char *input)
{
	int i = 0;
	char *array[512];
	char *token = strtok(input, "\n ");
	while (token != NULL)
	{
		array[i++] = token;
		char *token = strtok(NULL, "\n ");
	}

	array[i] = NULL;

}

void execute(void)
{
	char *array[512];
	int pid = fork();
	if (pid != 0)
	{
		int s;
		waitpid(-1, &s, 0);
	}
	else
	{
		if(execvp(array[0], array) == -1)
		{
			perror("Wrong command");
			exit(errno);
		}
	}
}

int main(void)
{
	char *input = NULL;
	size_t capline = 0;
	int i;
	char *token;
	char *array[512];
	
	startDisplay();
	
	while(1)
	{
		displayPrompt();
		getline(&input, &capline, stdin);
		
		if (strcmp(input, "\n") == 0)
		{
			perror("Please type in a command " );
			continue;
		}
		
		makeTokens(input);
		
		if (strcmp(array[0], "q") == 0)
		{
			printf("SYSTEM : Shell is exit\n");
			return 0;
		}
		
		execute();
		
	}
}
