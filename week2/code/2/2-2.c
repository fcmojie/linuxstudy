
#include"ch2.h"
int main()
{
	int ret;
	printf("2-2 is runing!\n");
	ret=write(1,"Hello World!\n",13);
	sleep(100);
	exit(0);
}
