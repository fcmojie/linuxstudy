#include "ch3.h"

int main()
{
	struct iobuf{
		char buf[8];
		char others[8];
	}buffer;
	memset(&buffer,'\0',sizeof(struct iobuf));
	fprintf(stdout,"用gets读取控制台数据（设置buf长度为8）\n");
	gets(buffer.buf);
	fprintf(stdout,"输出gets获取到buf里的数据:%s\n",buffer.buf);
	fprintf(stdout,"输出buffer.others中的数据，为溢出数据：%s\n",buffer.others);
	exit(0);
}
