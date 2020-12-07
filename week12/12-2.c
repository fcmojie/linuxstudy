#include "ch12.h"

int main()
{
	int fd1[2],fd2[2],i;
	pid_t k;
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

	k=fork();
	if(k<0)
	{
		perror("fork failed!\n");
                exit(-1);
	}
	else if(k==0)
	{
		close(fd1[1]);
		close(fd2[0]);
		i=read(fd1[0],buf,sizeof(buf));
		if(i<=0)
		{
			printf("child recieve failed!\n");
		}
		else
		{
			fprintf(stdout,"child %d recieve %s from parent! total = %d\n",getpid(),buf,strlen(buf));
			sprintf(buf,"%d recieve hello from %d",getpid(),getppid());
		}
		i=write(fd2[1],buf,sizeof(buf));
		if(i>0)
		{
			printf("child %d send success!\n",getpid());
		}
		close(fd1[0]);
		close(fd2[1]);

		exit(0);
	}
	else
	{
		close(fd1[0]);
		close(fd2[1]);
		sprintf(buf,"%d say hello to %d",getpid(),k);
		i=write(fd1[1],buf,sizeof(buf));
		if(i>0)
		{
			printf("parent %d send success!\n",getpid());
		}
		wait(NULL);
		i=read(fd2[0],buf,sizeof(buf));
		if(i<=0)
                {
                        printf("parent recieve failed!\n");
                }
                else
                {
                        fprintf(stdout,"parent %d recieve %s from child! total = %d\n",getpid(),buf,strlen(buf));
                }
		close(fd1[1]);
		close(fd2[0]);

		return 0;
	}
}
