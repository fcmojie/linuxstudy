#include "ch09.h"
int g=0;
int main()
{
	//File *out;
	pid_t pid;
	//if((out = fopen("out.dat","a+"))==NULL)
	//{
	//	err_exit("openfile failed\n");
	//}
	if(pid = fork()<0)
	{
		err_exit("fork failed!\n");
	}
	if(pid == 0)
	{
		
		printf("pid:%d  2pid = %d, ppid= %d\n",pid,getpid(),getppid());
		//if(pid=fork()<0)
		//{
		//	err_exit("fork failed!\n");
		//}
		//else if(pid ==1 ){
		//	printf("pid:%d  3pid = %d, ppid= %d\n",pid,getpid(),getppid());
		//	exit(1);
		//}
		//exit(0);	
	
	}
	else
	{
		printf("pid:%d  1pid = %d, ppid= %d\n",pid,getpid(),getppid());
	}
	
}
