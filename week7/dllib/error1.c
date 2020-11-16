#include "../ch07.h"
int *p,x;
int main()
{
	//未初始化的前提下会报段错误
	int *q;
	p=&x;
	*p=1;
	q=(int *)malloc(sizeof(int));
	*q=2;
	printf("*p=%d,*q=%d\n",*p,*q);
	return 0;
}
