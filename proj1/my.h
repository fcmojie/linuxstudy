#ifndef _MY_H_
#define _MY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
typedef struct user{
	int id;
	char name[8];
	char htel[12];
	char tel[12];
}recorder;

recorder *input(void);
int save(recorder *recorder);
#endif

