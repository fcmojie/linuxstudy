#include "ch07.h"

int main(int argc, char *argv[])
{
	int a, b, sum;
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	sum=a+b;
	printf("a+b=%d",sum);
	return 0;
}
