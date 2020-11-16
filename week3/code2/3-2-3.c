#include "ch2.h"

int main()
{
	FILE *fp;
	fp=fdopen(1,"w+"); //1为文件描述符
	fprintf(fp, "test data %s\n", "hello world");
	fclose(fp);
	return 0;
}
