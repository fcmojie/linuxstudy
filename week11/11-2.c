#include "ch11.h"

int main()
{
	pid_t pid1;
	pid1=fork();
	if(pid1<0)
	{
		perror("fork pid1 error!\n");
		exit(-1);
	}
	else if(pid1 == 0)
	{	
		printf("child1 : pid = %d,ppid = %d\n",getpid(),getppid());
		exit(1);
	}
	else
	{
		pid_t pid2;
                pid2=fork();
		if(pid2<0)
		{
			perror("fork pid2 error!");
			exit(-1);
		}else if(pid2 == 0)
		{
			printf("child2 : pid = %d,ppid = %d\n",getpid(),getppid());
			exit(1);
		}
		else{
			int p1,p2,s1,s2;
			p1=wait(&s1);
			p2=wait(&s2);
			if(p1==pid1)
			{
				printf("parent wait for child1 %d : exit code %d\n",p1,WEXITSTATUS(s1));
			}
			else
			{
				printf("parent wait for child2 %d : exit code %d\n",p1,WEXITSTATUS(s1));
			}
			if(p2==pid1)
                        {
                                printf("parent wait for child1 %d : exit code %d\n",p2,WEXITSTATUS(s1));
                        }
                        else
                        {
                                printf("parent wait for child2 %d : exit code %d\n",p2,WEXITSTATUS(s1));
                        }
			return 0;
		}
	}
}
