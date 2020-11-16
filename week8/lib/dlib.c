#include "../ch08.h"
void dynamic_lib_fun_call(void)
{
	printf("Dynamic Lib Fun Called!\n");
}

void mysort(void)
{
	int sort[10],i,j,tamp;
	printf("请输入十个整数：\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&sort[i]);
	}
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(sort[i]<sort[j])
			{
				tamp=sort[i];
				sort[i]=sort[j];
				sort[j]=tamp;
			}
		}
	}	
	 printf("降序排序后结果为:\n");
        for(i=0;i<10;i++)
        {
                printf("%d\n",sort[i]);
        }

	for(i=0;i<9;i++)
        {
		for(j=i+1;j<10;j++)
                {
                	if(sort[i]>sort[j])
                        {
                        	tamp=sort[i];
                                sort[i]=sort[j];
                                sort[j]=tamp;
                        }
                }
         }
	printf("升序排序后结果为:\n");
	for(i=0;i<10;i++)
	{
		printf("%d\n",sort[i]);
	}
}

