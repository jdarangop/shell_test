#include <stdio.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *line = NULL;
	pid_t proceso;
	size_t len;
	char *args;
	const char *point = {"/bin/ls"};

	while(1)
	{
		printf("$ ");
		getline(&line, &len, stdin);
		/*printf("Linea: %s\n", line);*/
		if(strcmp(line, "ls\n") == 0)
		{
			args = strtok(line, " \n");
			proceso = fork();
			if(proceso == 0)
			{
				execve(point[0], args, NULL);
			}
			else
				wait(NULL);
		}
		else
		{
			printf("Comando no encontrado\n");
		}
	}
}

