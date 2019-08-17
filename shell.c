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
	char *args[1024];
	char *tmp = "/bin/";
	/*const char *point = {"/bin/ls"};*/

	while(1)
	{
		printf("$ ");
		getline(&line, &len, stdin);
		/*printf("Linea: %s\n", line);*/
		args[1024] = (char *)strtok(line, " ");
		if(strcmp(line, "ls\n") == 0)
		{
			strcat(tmp, args[0]);
			proceso = fork();
			if(proceso == 0)
			{
				execve(tmp, args, NULL);
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

