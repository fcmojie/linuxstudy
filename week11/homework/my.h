#include "../ch11.h"

void prtinfo(char *s)
{
	FILE *fp;
	if((fp = fopen("log.dat","a"))==NULL)
        {
                printf("open() failed!\n");
		exit(-1);
        }
        else
        {
        	time_t t;
                char buf[1024];
                time(&t);
                ctime_r(&t,buf);
                fprintf(fp,"%s\tpid=%d\t%s",s,getpid(),buf);
        }
	fclose(fp);
}
