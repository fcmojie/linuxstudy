#include "ch10.h"

int main()
{
	int r1,r2,r3,r4;
	r1=fork();
	
	if(r1<0)
	{
		perror("fork1 failed!\n");
		exit(-1);
	}
	else if(r1==0)
	{
		r4=fork();
		if(r4<0)
		{
			perror("fork11 failed!\n");
			exit(-1);
		}
		else if(r4==0)
		{
			printf("child 11 : pid = %d, ppid = %d \n",getpid(),getppid());
			exit(0);
		}else
		{
			printf("child 1 : pid = %d, ppid = %d \n",getpid(),getppid());
			exit(0);
		}
	}
	else
	{	wait(NULL);
		r2=fork();
		if(r2<0)
		{
			perror("fork2 failed!\n");
                	exit(-1);
		}
		else if(r2==0)
		{
			printf("child 2 : pid = %d, ppid = %d \n",getpid(),getppid());
                        exit(0);
		}
		else
		{
			r3=fork();
			if(r3<0)
                	{
                        	perror("fork3 failed!\n");
                	        exit(-1);
                	}
                	else if(r3==0)
                	{
                        	printf("child 3 : pid = %d, ppid = %d \n",getpid(),getppid());
                        	exit(0);
                	}
			else
			{
				wait(NULL);
				wait(NULL);
				wait(NULL);
				printf("parent : pid = %d, r1 = %d, r2 = %d\n",getpid(),r1,r2);
				return 0;
			}
		}
	}
}
