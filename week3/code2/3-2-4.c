#include "ch2.h"

int main()
{
	FILE *fp;
	int fd;
	fd=open("./test1.txt",O_RDWR);
	fp=fdopen(fd,"w+");
	fprintf(fp, "test data %s\n", "hello world!!!");
	fclose(fp);
	return 0;
}
