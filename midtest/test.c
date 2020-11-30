#include "my.h"

int main()
{
	pid_t pid;
	printf("----before fork");
	pid=fork();
	if(pid==0)
	{
		printf("child\n");
		exit(0);
	}
	else
	{
		printf("father\n");
	}
}
