#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t my_pid;
	char *args[] = {"./exec", NULL};


	my_pid = fork();
	if (my_pid == 0)
	{
		printf("This is my child PID %d and parent %d\n", getpid(), getppid());
		execv(args[0], args);
	}
	else
	{
		printf("This is my parent PPID %d and parent %d\n", getpid(), getppid());
		wait(NULL);
		printf("Despues del padre");
	}
	printf("hola\n");
	return (0);
}
