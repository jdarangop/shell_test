#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h>

int main(void)
{
	char *line = NULL;
	size_t len;
	/*size_t output;*/


	while(1)
	{
		printf("$ ");
		getline(&line, &len, stdin);
		printf("%s", line);
	}

	return (0);
}
