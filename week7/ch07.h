#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <dlfcn.h>
void err_exit(char *s)
{
	printf("USAGE : *s if faile!\n");
	exit(1);
}
