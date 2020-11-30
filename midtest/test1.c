#include "my.h"
int g=0;

int main()
{
	int status;
	pid_t pid;
	pid=fork();
	//if(pid!=0)
	//{
	//	printf("out1:repid=%d  pid=%d ppid=%d\n",pid,getpid(),getppid());

	//}
	pid=fork();
	//if(pid==0)
	//{
	//	printf("out2:repid=%d  pid=%d ppid=%d\n",pid,getpid(),getppid());
	//	exit(0);
	//}
	//else{
		wait(&status);
		printf("out:repid=%d  pid=%d ppid=%d address:g=%x,%d\n",pid,getpid(),getppid(),&g,g);
	//}
}
