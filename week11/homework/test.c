#include "../ch11.h"

int main()
{
	FILE *fp;
	if((fp = fopen("log.dat","w"))==NULL)
	{
		err_exit("open() failed"); //头文件里的错误信息函数
	}
	else
	{	
		time_t t;
                char buf[1024];
                time(&t);
                ctime_r(&t,buf);
		fprintf(fp,"%s",buf);
	}
	fclose(fp);
	sleep(5);
	if((fp = fopen("log.dat","a"))==NULL)
        {
                err_exit("open() failed"); //头文件里的错误信息函数
        }
        else
        {
                time_t t;
                char buf[1024];
                time(&t);
                ctime_r(&t,buf);
                fprintf(fp,"%s",buf);
        }
	return 0;
}
