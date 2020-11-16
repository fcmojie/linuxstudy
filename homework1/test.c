#include <stdio.h>

int main()
{
	float fl = 0;
	int o = 0x00800000;
	fl = fl | o;
	printf("%e\n",fl);
	return 0;
}
