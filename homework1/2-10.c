#include "ch3.h"

int main()
{
	FILE *fd;
	char buf[100];
	int rc = 0, i, size=0, seek;
	if((fd = fopen("list.txt","r")) == NULL)
	{
		printf("文件打开失败！");
	}
	for(i=1000;i>=1;i=i/10)
	{
		rc += i*(fgetc(fd)-'0');
	}
	seek = (rc+1)*4; //将seek定位到记录长度的记录之后；
	printf("总记录数为%d条，请输入您要读取的记录（从1开始标号）:\n", rc);
	scanf("%d",&rc);
	for(int j=1;j<=rc;j++)
	{
		size = 0;
		fseek(fd,j*4,SEEK_SET);
		for(i=1000;i>=1;i=i/10)
        	{
                	size += i*(fgetc(fd)-'0');
        	}
		if(j!=rc)
		{
			seek+=size; //将seek定位到要读取的记录之前；
		}
	}
	fseek(fd, seek, SEEK_SET);
	printf("当前记录长度为%d字节:\n",size);
	printf("%s\n",fgets(buf,size+1,fd));
	fclose(fd);
	exit(0);
}
