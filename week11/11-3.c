#include "ch11.h"
void pr_exit(int status,pid_t pid)
{
	int sig;
	if (WIFEXITED(status))
	{
		printf("process %d normal termination, exit status = %d\n",pid,WEXITSTATUS(status));
	}else if(WIFSIGNALED(status))
	{
		sig = WTERMSIG(sig);
		printf("process %d abnormal termination, signal number = %d%s:\n",pid, sig,
		#ifdef WCOREDUMP
				WCOREDUMP(status) ? "(core file generated)" : "");
		#else
				"");
		#endif
		psignal(sig,"");
	}else if(WIFSTOPPED(status))
	{
		sig = WSTOPSIG(status);
		printf("process %d stopped, signal number = %d: ",pid,sig);
		psignal(sig,"");
	}
}

int main()
{
	pid_t pid1,pid2,pid3;
	pid1=fork();
	if(pid1<0)
	{
		perror("fork pid1 error!\n");
		exit(-1);
	}
	else if(pid1 == 0)
	{	
		printf("child1 : pid = %d,ppid = %d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
                pid2=fork();
		if(pid2<0)
		{
			perror("fork pid2 error!");
			exit(-1);
		}else if(pid2 == 0)
		{
			printf("child2 : pid = %d,ppid = %d\n",getpid(),getppid());
			exit(0);
		}
		else{
			pid3=fork();
			if(pid3<0)
	                {
        	                perror("fork pid2 error!");
                	        exit(-1);
               		}else if(pid3 == 0)
                	{
				int a;
                        	printf("child2 : pid = %d,ppid = %d\n",getpid(),getppid());
				while(1);
                       		exit(0);
                	}
			else
			{
				int r1,r2,r3,s1,s2,s3;
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				if(r1==pid1)
				{
					printf("parent wait for child1 %d : exit code %d\n",r1,WEXITSTATUS(s1));
				}
				else if(r1 == pid2)
				{
					printf("parent wait for child2 %d : exit code %d\n",r1,WEXITSTATUS(s1));
				}
				else
				{
					printf("parent wait for child3 %d : exit code %d\n",r1,WEXITSTATUS(s1));
				}

				if(r2==pid1)
                        	{
                                	printf("parent wait for child1 %d : exit code %d\n",r2,WEXITSTATUS(s2));
                        	}
                       		else if(r2 == pid2)
                        	{
                                	printf("parent wait for child2 %d : exit code %d\n",r2,WEXITSTATUS(s2));
                        	}
				else
                                {
                                        printf("parent wait for child3 %d : exit code %d\n",r2,WEXITSTATUS(s2));
                                }

				if(r3==pid1)
                                {
                                        printf("parent wait for child1 %d : exit code %d\n",r3,WEXITSTATUS(s3));
                                }
                                else if(r3 == pid2)
                                {
                                        printf("parent wait for child2 %d : exit code %d\n",r3,WEXITSTATUS(s3));
                                }
				else
                                {
                                        printf("parent wait for child3 %d : exit code %d\n",r3,WEXITSTATUS(s3));
                                }
				pr_exit(s1,r1);
				pr_exit(s2,r2);
				pr_exit(s3,r3);

				return 0;
			}
		}
	}
}
