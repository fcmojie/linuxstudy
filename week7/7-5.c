#include "ch07.h"
static void callback1(void)
{
	printf("------CallBack1------\n");
}
static void callback2(void)
{
	printf("------CallBack2------");
}
static void callback3(void)
{
        printf("------CallBack3------");
}

int main(void)
{
	atexit(callback1); //可以用于注册回调函数
	atexit(callback2);
	atexit(callback3);
	printf("----Main exit!----");
	exit(0);
	//_exit(0);
}
