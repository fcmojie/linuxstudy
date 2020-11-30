#include "./ch10.h"

int main()
{
	int s1,s2;
	pid_t pid1,pid2;
	pid1 = fork();
	if(pid1 < 0)
	{
		printf("fork failed\n");
		exit(-1);
	}else if(pid1 == 0)
	{
		printf("child 1 : pid = %d, ppid = %d\n",getpid(),getppid());
		while(1);
		exit(98);
	}
	else{
		pid2 = fork();
		if(pid2 < 0)
	        {
        	        printf("fork failed\n");
                	exit(-1);
        	}else if(pid2 == 0)
        	{
                	printf("child 2 : pid = %d, ppid = %d\n",getpid(),getppid());
               		exit(99);
        	}
		else{
			waitpid(pid1,&s1,WNOHANG);
			waitpid(pid2,&s2,0);
			printf("father : pid = %d, pid1 = %d, pid2 = %d, s1 = %d, s2 = %d\n",getpid(),pid1,pid2,WEXITSTATUS(s1),WEXITSTATUS(s2));
			return 0;
		}

	}
}
