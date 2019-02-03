#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Max 100

//stores the values takig user input
void store_eq(float a[Max][Max],int n)
{
	printf("Enter the matrix:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			scanf(" %f",&a[i][j]);
		}
	}
	return;
}

void printm(float a[Max][Max], int n)
{
	printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%f ",a[i][j]);
		printf("\n");
	}
	printf("\n");
	return;
}

void swap_rows(float a[Max][Max], int n, int x, int y)
{	
	for(int i=0;i<=n;i++)
	{
		float temp;
		temp=a[x][i];
		a[x][i]=a[y][i];
		a[y][i]=temp;
	}
		
	return;
}

void max_swap(float a[Max][Max], int n,int i)
{
	int max=i;
	for(int i2=i;i2<n;i2++)
		if(a[i2][0]>a[max][0])
			max=i2;

	if(i!=max)
		swap_rows(a,n,i,max);
	
	float c=a[i][i];
	if(fabs(c)<0.00001)
	{
		printf("Infinite or no solution!\n");
		exit(0);
	}
	for(int j=0;j<=n;j++)
		a[i][j]/=c;
	
	return;
}



void substract_row(float a[Max][Max],int n, int x, int y)
{
	if(a[x][x]==0)
		return;

	float c=a[y][x]/a[x][x];
	for(int i=x;i<n+1;i++)
		a[y][i]-=a[x][i]*c;
	
}

void pivot(float a[Max][Max], int n, int i)
{
	for(int j=n-1;j>i;j--)
		substract_row(a,n,i,j);
}



void echlon(float a[Max][Max], int n)
{
	for(int i=0;i<n;i++)
	{
		max_swap(a,n,i);
		pivot(a,n,i);
	}
}


void roots(float a[Max][Max], float *x, int n)
{
	for(int i=n-1;i>=0;i--)
	{
		float root=a[i][n];
		for(int j=i+1;j<n;j++)
			root-=x[j]*a[i][j];
		root/=a[i][i];
		x[i]=root;
	}
}


void print_roots(float *x, int n)
{
	printf("\nThe solution is:\n");
	for(int i=0;i<n;i++)
		printf("%f\n",x[i]);
}


//==================================================================================================
int main()
{
	int n;
	printf("Enter the number of variables :");
	scanf("%d",&n);
	

	float a[Max][Max];
	store_eq(a,n);
	

	//printm(a,n);
	echlon(a,n);
	//printm(a,n);
	
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(a[i][i]==0)
		{
			printf("Infinite or no solution\n");
			flag=1;
			break;
		}
	}
	if(flag)
		return 0;
	
	float x[n];
	roots(a,x,n);
	print_roots(x,n);
	
	return 0;
}
