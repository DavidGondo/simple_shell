#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int _exit(char *exit)
{
  char *array[512];
	if (strcmp(array[0], "exit") == 0)
	{
	  printf("SYSTEM : Shell is exit\n");
	  return 0;
	}
	
}

int main(void)
{
  _exit();
}
