#include <stdio.h>

int main(void)
{


  char command;
  printf("$");
  scanf("%s",&command);
  while (command !='\0')
    {
      printf("$");
      scanf("%s\n",&command);
    }
}
