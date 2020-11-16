#include "ch2.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	if((fp=fopen("test1.txt","w"))==NULL)
		perror("open failed!\n");
	
	for(int i=1; i<argc; i++)
	{
		fprintf(fp,"%s",argv[i]);
		printf("[%d] : %s\n", i, argv[i]);
	}
	fclose(fp);
	return 0;
}
