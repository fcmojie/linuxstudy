#include "ch10.h"

int main()
{
	int r;
	r=fork();
	if(r<0)
	{
		perror("fork failed!\n");
	}
	else if(r==0)
	{
		int r1;
		printf("pid = %d, ppid = %d\n",getpid(),getppid());
		r1=execl("./test","./test","简佳龙","牛逼",NULL);
		printf("child end!");
		exit(1);
	}
	else{
		int rt,s;
		rt=wait(&s);
		printf("10-6 : rt = %d, status = %d\n",r,WEXITSTATUS(s));
		return 0;
	}
}
