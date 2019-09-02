#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generator(int i,int* a)
{
	int n,flag=0;
	while(1)
	{
		n=rand()%(60000)+1;
		for(int j=0;j<i;j++)
		{
			if(a[j]==n)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			return n;
	}
}	



int main()
{
	FILE* file;
	
	int n;
	int a[60000];
	file=fopen("1.4.txt","w");
	
	srand(time(0));
	printf("printing line no:\n");
	for(int i=0;i<60000;i++)
	{
		n=generator(i,a);
		fprintf(file,"%d\n",n);
		printf("\r%d",i+1);
	}
	printf("\n");
	fclose(file);
	return 0;
};


