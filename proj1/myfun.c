#include "my.h"
recorder *input(void)
{
		recorder *temp;
        	temp = (recorder*)malloc(sizeof(recorder));
	//int er;
		printf("Please input userid:\n");
		scanf("%d",&temp->id);
		printf("Please input name:\n");
		scanf("%s",temp->name);
		printf("Please input htel:\n");
		scanf("%s",temp->htel);
		printf("Please input tel:\n");
		scanf("%s",temp->tel);
		//if(er==0)
		//{
		//	printf("save failed!\n");
		//	exit(0)
		//}
		//else if(er==1)
		//{
		//	printf("userid had repeated!\n")
		//}
		//printf("If you want add more one data(y(1) or n(0)):\n");
		//scanf("%d",&flag);
	return temp;
};

int save(recorder *recorder)
{
	FILE *fp;
        if((fp=fopen("./user.dat","a+"))==NULL)
        {
                return 0;
        }
	if(fprintf(fp,"%03d\t%s\t%s\t%s\n",recorder->id,recorder->name,recorder->htel,recorder->tel)<0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	fclose(fp);
}
