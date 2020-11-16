#include "ch2.h"

int main()
{
	FILE *fp;
	char buf[80];
	size_t num;
	memset(buf,0,sizeof(buf));
	if((fp=fopen("test1.txt","w"))==NULL)
		perror("open failed!\n");
	fgets(buf,sizeof(buf),stdin);
	printf("Content id %s\n", buf);
	num = fwrite(buf,sizeof(buf),1,fp);
	printf("items = %ld\n", num);
	fclose(fp);
	return 0;
}
