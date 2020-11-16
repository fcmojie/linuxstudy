#include "../ch08.h"

int main()
{
	void *fpt = dlopen("./libdlib.so",RTLD_NOW);
	if(!fpt)
	{
		printf("dlopen faild!\n");
		exit(1);
	}
	void (*fp)(void)=dlsym(fpt,"mysort");
	if(!fp)
	{
		printf("Dlsym Failed!\n");
		exit(1);
	}
	fp();
	dlclose(fpt);
	return 0;
}
