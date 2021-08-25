#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

/**
*startDisplay - first prompt
*Retun: void
*/
<<<<<<< HEAD:epo.c

char *input = NULL;
size_t capline = 0;
int i;
char *token;
char *array[512];

void startDisplay()
=======
void startDisplay(void)
>>>>>>> 7f410ce806a6080abf387a7ed1772b11f0fce2be:hsh.c
{
	printf("**************************************************************\n");
	printf("*WELCOME TO THE COMMAND LINE INTERPETER                      *\n");
	printf("*TO RUN A COMMAND SIMPLY TYPE YOUR COMMAND AND PRESS 'ENTER' *\n");
	printf("*EXAMPLE: ls -a                                              *\n");
	printf("*TO EXIT TYPE 'q'                                            *\n");
	printf("**************************************************************\n");
}

/**
*displayPrompt - prompt to display when program starts
*Return: void
*/
void displayPrompt(void)
{
	printf("$");
}

/**
*makeTokens - tokenixning the line
*@input: input to be token
*Return: void
*/
void makeTokens(char *input)
{
<<<<<<< HEAD:epo.c
i = 0;
token = strtok(input, "\n ");
while (token != NULL)
{
array[i++] = token;
token = strtok(NULL, "\n ");
}
array[i] = NULL;
=======
	int i = 0;
	char *array[512];
	char *token = strtok(input, "\n ");

	while (token != NULL)
	{
		array[i++] = token;
		char *token = strtok(NULL, "\n ");
	}

	array[i] = NULL;
>>>>>>> 7f410ce806a6080abf387a7ed1772b11f0fce2be:hsh.c

}

/**
*execute - executing the program
*Return: void
*/
void execute(void)
{
<<<<<<< HEAD:epo.c
 int pid = fork();
 if (pid != 0)
 {
   int s;
   waitpid(-1, &s, 0);
     } else {
   if(execvp(array[0], array) == -1)
     {
		 perror("Wrong command");
		 exit(errno);
     }
	    }
}

int main()
{
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
=======
	char *array[512];
	int pid = fork();

	if (pid != 0)
	{
		int s;

		waitpid(-1, &s, 0);
	}
	else
	{
		if (execvp(array[0], array) == -1)
		{
			perror("Wrong command");
			exit(errno);
		}
	}
}

/**
*main - Entry to program
*Return: 0 on success
*/
int main(void)
{
	char *input = NULL;
	size_t capline = 0;
	int i;
	char *token;
	char *array[512];

	startDisplay();

	while (1)
>>>>>>> 7f410ce806a6080abf387a7ed1772b11f0fce2be:hsh.c
	{
		displayPrompt();
		getline(&input, &capline, stdin);

		if (strcmp(input, "\n") == 0)
		{
			perror("Please type in a command ");
			continue;
		}

		makeTokens(input);

		if (strcmp(array[0], "q") == 0)
		{
			printf("SYSTEM : Shell is exit\n");
			return (0);
		}

		execute();

	}
}
