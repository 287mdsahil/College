#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n_of_n 50

unsigned long long gen_random()
{
	unsigned long long n=0;
	int ten=1;
	//srand(time(NULL));
	for(int i=0;i<20;i++)
	{
		n=n+abs(ten*(rand()%9+1));
		ten*=10;
	}
	return (n);
}


//function to generate prime numbers-------------------------------------------------------
int* prime_generate(int *n)
{
	int a[9000];
	for(int i=0;i<9000;i++)
		a[i]=i+1000;
	
	
	for(int i=2;i<=5000;i++)
	{
		for(int j=2;i*j<10000;j++)
		{
			//if(i*j<5000)
			//	printf("%d\t%d\t%d\n",i*j,i,j);
			if(i*j>=1000)
				a[i*j-1000]=0;
		}
	}
	
	
	int *p;
	p=(int*) malloc(1500*sizeof(int)); 
	int index=0;
	for(int i=0;i<9000;i++)
		if(a[i]!=0)
		{
			p[index]=a[i];
			index++;
		}
	
	*n=index;
	return p;		
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main()
{
	int n;
	int *p=prime_generate(&n);


	
	
	srand(time(0));
	int t=3;
	while(t--)
	{
		int prime_index=rand()%n;
		printf("The prime number is : %d\n\n",p[prime_index]);
		
		printf("random large number\tremainder\n------------------------------------\n");
		
		int num[n_of_n];
		for(int i=0;i<n_of_n;i++)
		{
			num[i]=gen_random();
			unsigned long long mod=num[i]%(unsigned long long)(p[prime_index]);
			printf("%lld\t\t%d\n",num[i],mod);
		}
		printf("=========================================================\n\n");
	}
	
	
	
	return 0;
}
