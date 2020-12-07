#include "ch12.h"

int main()
{
	int fd[2],i;
	pid_t k;
	char buf[200];

	if((pipe(fd))<0)
	{
		perror("pipe failed!\n");
	}
	k=fork();
	if(k<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(k==0)
	{
		close(fd[0]);
		close(1);
		dup(fd[1]);
		execlp("./test","test","123","456",NULL);
	}
	else
	{
		close(fd[1]);
		i=read(fd[0],buf,sizeof(buf));
		if(i<=0)
		{
			printf("get failed!\n");
		}
		else
		{
			fprintf(stdout,"parent:\n%s",buf);
		}
		close(fd[0]);
		return 0;
	}
}
