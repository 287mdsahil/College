#include<stdio.h>
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
	printf("\n");//stores the values takig user input
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
	for(int j=0;j<=n;j++)
		a[i][j]/=c;
	return;
}



void substract_row(float a[Max][Max],int n, int x, int y)
{
	if(a[x][x]==0)
		return;

	float c=a[y][x]/a[x][x];
	for(int i=0;i<n+1;i++)
		a[y][i]-=a[x][i]*c;
	
}


void pivot(float a[Max][Max], int n, int i)
{
	for(int j=n-1;j>i;j--)
		substract_row(a,n,i,j);
	return;
}

void pivot2(float a[Max][Max], int n, int i)
{
	for(int j=0;j<i;j++)
		substract_row(a,n,i,j);
	return;
}


void echlon(float a[Max][Max], int n)
{
	for(int i=0;i<n;i++)
	{
		max_swap(a,n,i);
		pivot(a,n,i);
	}
	return;
}


void print_roots(float *x, int n)
{
	printf("\nThe solution is:\n");
	for(int i=0;i<n;i++)
		printf("%f\n",x[i]);
}



void u_echlon(float a[Max][Max], int n)
{
	for(int i=n-1;i>0;i--)
	{
		pivot2(a,n,i);
	}
	return;
}

void scale(float a[Max][Max], int n)
{
	for(int i=0;i<n;i++)
	{
		float c=a[i][i];
		for(int j=0;j<=n;j++)
		{
			a[i][j]=a[i][j]/c;
			
			printf("%f %d %d\n",a[i][j], i, j);
		}
	}
	return;
}

void roots(float a[Max][Max], float *x, int n)
{
	for(int i=0;i<n;i++)
		x[i]=a[i][n];
	return;
}

//==================================================================================================
int main()
{
	int n;
	printf("Enter the number of variables :");
	scanf("%d",&n);
	

	float a[Max][Max];
	store_eq(a,n);
	

	
	echlon(a,n);
	
	//scale(a,n);
	//printm(a,n);

	u_echlon(a,n);
	
	//printm(a,n);
	
	
	float x[n];
	roots(a,x,n);
	print_roots(x,n);
	
	return 0;
}
