#include<stdio.h>


long fact_iter(int n)
{
	long fact=1;
	for(int i=0;i<n;i++)
		fact*=(i+1);
	return fact;
}

long fact_rec(int n)
{
	if(n==1 || n==0)
		return 1;
	else 
		return n*fact_rec(n-1);
}

int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	long fact1=fact_iter(n);
	long fact2=fact_rec(n);
	
	printf("(iteration)Factorial of %d : %ld\n",n,fact1);
	printf("(recursion)Factorial of %d : %ld\n",n,fact2);

	return 0;
}
