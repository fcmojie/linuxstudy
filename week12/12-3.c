#include "ch12.h"

int main()
{
	int fd1[2],fd2[2],i;
	pid_t k1,k2;
	char buf[100];
	memset(buf,0,sizeof(buf));
	if((pipe(fd1))<0)
	{
		perror("pipe1 failed!\n");
		exit(-1);
	}
	if((pipe(fd2))<0)
        {
                perror("pipe2 failed!\n");
                exit(-1);
        }

	k1=fork();
	if(k1<0)
	{
		perror("fork failed!\n");
                exit(-1);
	}
	else if(k1==0)
	{
		sleep(2);
		close(fd1[1]);
		close(fd2[0]);
		i=read(fd1[0],buf,sizeof(buf));
		if(i<=0)
		{
			printf("child1 recieve failed!\n");
		}
		else
		{
			fprintf(stdout,"child1 %d recieve %s from child2! total = %d\n",getpid(),buf,strlen(buf));
			sprintf(buf,"%d recieve hello from child2",getpid(),k2);
		}
		i=write(fd2[1],buf,sizeof(buf));
		if(i>0)
		{
			printf("child1 %d send success!\n",getpid());
		}
		close(fd1[0]);
		close(fd2[1]);

		exit(0);
	}
	else
	{
		k2=fork();
		if(k2<0)
		{
			perror("fork failed!\n");
		}
		else if(k2==0)
		{
			close(fd1[0]);
			close(fd2[1]);
			sprintf(buf,"%d say hello to %d",getpid(),k1);
			i=write(fd1[1],buf,sizeof(buf));
			if(i>0)
			{
				printf("child2 %d send success!\n",getpid());
			}
			sleep(5);
			i=read(fd2[0],buf,sizeof(buf));
			if(i<=0)
                	{
                	        printf("child recieve failed!\n");
                	}
               		else
                	{
                        	fprintf(stdout,"child2 %d recieve %s from child1! total = %d\n",getpid(),buf,strlen(buf));
                	}
			close(fd1[1]);
			close(fd2[0]);
		}
		else
		{
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[0]);
                        close(fd2[1]);
			wait(NULL);
			wait(NULL);
			printf("parent: child1 = %d,child2 = %d\n",k1,k2);
			return 0;
		}
	}
}
