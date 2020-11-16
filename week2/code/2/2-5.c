#include"ch2.h"

int main()
{
	int cnt;
	for(cnt=0;cnt<=1020;cnt++)
	{	
		char name[64];
		snprintf(name, sizeof(name),"%d.txt", cnt);
		remove(name);
	}
	return 0;
}
