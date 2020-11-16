#include "my.h"
#include "myfun.c"
int main()
{
	recorder *temp;
	temp = (recorder*)malloc(sizeof(recorder));
	temp = input();
	save(temp);

	return 0;
}
