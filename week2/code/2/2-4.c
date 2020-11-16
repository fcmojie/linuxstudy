#include "ch2.h"
int main()
{
	int cnt=0;
	int fd=1;
	while(fd){
		char name[64];
		snprintf(name, sizeof(name),"%d.txt", cnt);
		fd = creat(name,0644);
		cnt++;
	}
	return 0;
}
