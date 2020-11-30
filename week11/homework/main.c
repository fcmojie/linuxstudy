#include "my.h"
int main()
{	
	char *buf;
	pid_t pid1;
	pid1 = fork();
	if(pid1 < 0)
	{
		printf("pid fork failed!\n");
		exit(-1);
	}
	else if(pid1 == 0)
	{
		pid_t pid11;
		pid11 = fork();
		if(pid11 < 0)
		{
			printf("pid fork failed!\n");
			exit(-1);
		}
		else if(pid11 == 0)
		{
			printf("child11 : pid = %d, ppid = %d\n",getpid(),getppid());
			buf="child11";
			prtinfo(buf);
			sleep(2);
			exit(0);
		}
		else
		{
			int r11, s11;
			r11 = waitpid(pid11,&s11,0);
			printf("child1 : pid = %d, ppid = %d\n",getpid(),getppid());
			buf="child1";
			prtinfo(buf);
			sleep(1);
			exit(0);
		}
	}
	else
	{	pid_t pid2;
		pid2 = fork();
		if(pid2 < 0)
	        {
        	        printf("pid fork failed!\n");
                	exit(-1);
        	}
       		else if(pid2 == 0)
        	{
               		pid_t pid21;
                	pid21 = fork();
                	if(pid21 < 0)
                	{
                        	printf("pid fork failed!\n");
                        	exit(-1);
                	}
                	else if(pid21 == 0)
                	{
                        	printf("child21 : pid = %d, ppid = %d\n",getpid(),getppid());
				buf="child21";
				prtinfo(buf);
				sleep(1);
                        	exit(0);
                	}
                	else
                	{
                        	int r21, s21;
                        	r21 = waitpid(pid21,&s21,0);
                        	printf("child2 : pid = %d, ppid = %d\n",getpid(),getppid());
				buf="child2";
				prtinfo(buf);
				sleep(1);
                        	exit(0);
                	}
        	}
		else
		{
			int r1, r2, s1, s2;
			r1 = waitpid(pid1,&s1,0);
			r2 = waitpid(pid2,&s2,0);
			printf("parent : pid = %d, ppid = %d\n",getpid(),getppid());
			buf="parent";
			prtinfo(buf);
		//	sleep(100);
			return 0;
		}
	}
}
