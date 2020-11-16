
#include"ch2.h"
int main()
{
	int ret;
	char buf[101];
	int fd;
	memset(buf,0,sizeof(buf));
	fd=open("./test.data",O_CREAT|O_TRUNC|O_RDWR,0644);
	printf("2-2 is runing!\n");
	printf("%d:process is runing\n",getpid());
	ret=write(1,"Hello World!\n",13);
	printf("ret = %d\n", ret);
	printf("Please input data <=100:\n");
	fgets(buf,100,stdin);
	ret=write(fd,buf,sizeof(buf));
	printf("ret = %d\n", ret);
	exit(0);
}
