#include<stdio.h>
#include<time.h>
int call;
long itr_fibo(int n)
{
	long f1=1,f2=1,f=1;
	int loop;
	for(loop=0;loop<n-2;loop++)
	{
		f=f1+f2;
		f1=f2;
		f2=f;
	}
	return f;
}

long rec_fibo(int n)
{
	call++;
	if(n==1 || n==2)
		return 1;
	else
		return rec_fibo(n-1)+rec_fibo(n-2);
}

int main()
{
	//int n;
	//printf("Enter the number(n): ");
	//scanf("%d",&n);
	
	//long fn = itr_fibo(n);
	//printf("nth fibonachi number is: %ld\n",fn);
	
	for(int n=1;n<48;n++)
	{
		time_t end,beg;
		beg=time(NULL);
		call=0;
		long fn = rec_fibo(n);
		end=time(NULL);
		float timetaken=difftime(end,beg);
		printf("%d\t%ld\t\t%9.9f\t\t%ld\n",n,fn,timetaken,call);
	}
	return 0;
}
