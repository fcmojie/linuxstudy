#include "../ch07.h"

void dynamic_lib_call(void)
{
	printf("Dynamic lib is called\n");
}

void dsum(int max)
{
	int i, sum;
	
	for(i=1; i<=max; i++)
	{
		sum+=i;
	}
	printf("1到%d的累加和为：%d",max,sum);

}
