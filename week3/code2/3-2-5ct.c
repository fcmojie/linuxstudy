#include "ch2.h"

int main()
{
	FILE *fp;
	char buf[80];
	memset(buf,0,sizeof(buf));
	freopen("./test1.txt","a",stdout);
	printf("append new information!");
	fgets(buf,sizeof(buf),fp);
	printf("Content of file : %s\n", buf);
	fclose(fp);
	return 0;
}
