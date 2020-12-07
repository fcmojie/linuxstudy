#include "ch12.h"

int main()
{
	int fd11[2],fd12[2],fd21[2],fd22[2],i;
	pid_t k1,k2;
	char buf[100], *b="88";
	memset(buf,0,sizeof(buf));
	if((pipe(fd11))<0)
	{
		perror("pipe11 failed!\n");
		exit(-1);
	}
	if((pipe(fd12))<0)
        {
                perror("pipe11 failed!\n");
                exit(-1);
        }
	if((pipe(fd21))<0)
        {
                perror("pipe11 failed!\n");
                exit(-1);
        }
	if((pipe(fd22))<0)
        {
                perror("pipe11 failed!\n");
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
		close(fd21[0]);
		close(fd22[0]);
		close(fd21[1]);
		close(fd22[1]);
		close(fd11[0]);
		close(fd12[1]);
		while(1)
		{
			fgets(buf,sizeof(buf),stdin);
			i=write(fd11[1],buf,sizeof(buf));
			if(i<=0)
			{
				printf("child1 call failed!\n");	
			}
			i=read(fd12[0],buf,sizeof(buf));
			if(i<=0)
			{
				printf("child1 recieve failed!\n");
			}
			else
			{
				fprintf(stdout,"child1 %d recieve %s\n",getpid(),buf);
			}
			i=strncmp(b,buf,2);
			if(i==0)
			{
				close(fd11[1]);
				close(fd12[0]);
				break;
			}
		}
	}
	else
	{
		k2=fork();
		if(k2<0)
		{
			perror("fork failed!\n");
			exit(-1);
		}
		else if(k2==0)
		{
			close(fd11[0]);
			close(fd11[1]);
			close(fd12[0]);
			close(fd12[1]);
			close(fd21[0]);
			close(fd22[1]);
			printf("there is child2\n");
			close(fd21[1]);
			close(fd22[0]);
		}
		else
		{
			close(fd11[1]);
			close(fd12[0]);
			close(fd21[1]);
			close(fd22[0]);
			while(1)
			{	
				fgets(buf,sizeof(buf),stdin);
                		i=write(fd12[1],buf,sizeof(buf));
                		if(i<=0)
                		{
                        		printf("parent call failed!\n");
                		}
                		i=read(fd11[0],buf,sizeof(buf));
				if(i<=0)
				{
					printf("parent recieve failed!\n");
				}
				else
				{
                			fprintf(stdout,"parent %d recieve %s\n",getpid(),buf);
				}
			}
			close(fd11[0]);
			close(fd12[1]);
			close(fd21[0]);
			close(fd22[1]);
			wait(NULL);
			wait(NULL);
			return 0;
		}
	}

}
