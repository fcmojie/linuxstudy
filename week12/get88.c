#include "ch12.h"

int main()
{
	char buf[100];
	int i;
	char *b="88";
	memset(buf,0,sizeof(buf));
	while(1)
	{
		fgets(buf,sizeof(buf),stdin);
		printf("input message : %s\n",buf);
		printf("strlen %d\n",strlen(buf));
		i=strncmp(b,buf,2);
		printf("i=%d\n",i);
		if(i==0)
		{
			break;
		}
	}
	return 0;
}
