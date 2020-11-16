#include "ch5.h"

int main()
{
	size_t size=12;

	setvbuf(stdout,BUFSIZ,_IOFBF,size);
	printf("Hello World!");
	while(1);
	return 0;
}
