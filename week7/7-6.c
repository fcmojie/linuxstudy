#include "ch07.h"
static void callback1(void)
{
	printf("------CallBack1------\n");
}
static void callback2(void)
{
	printf("------CallBack2------\n");
}
static void callback3(void)
{
        printf("------CallBack3------\n");
}
static void __attribute__ ((destructor)) after_main()
{
        printf("---------After Main----------\n");
}


int main(void)
{
	atexit(callback1); //可以用于注册回调函数
	atexit(callback2);
	atexit(callback3);
	//按栈的方式调用
	printf("----Main exit!----\n");
	exit(0);
	//_exit(0);
}
