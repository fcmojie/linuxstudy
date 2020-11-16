#include <stdio.h>
#include <stdlib.h>

int main()
{
	int var;
	var = 0x7ffffff0;
	do
	{
		printf("int型变量不断加一直到溢出为变负数:%d\n", var);
		var+=0x00000001;
	}while(var>0);
	if(var<=0)
	{
		printf("最后一个值为int型的最大值。\n");
	}
	var = 0x80000010;
	do
        {
                printf("int型变量不断减一直到溢出为变正数:%d\n", var);
                var-=0x00000001;
        }while(var<0);
        if(var>=0)
        {
                printf("最后一个值为int型的最小值。\n");
        }
	//printf("float型为左右对称式分布，显示绝对值的最大最小值\n");
	return 0;
}
