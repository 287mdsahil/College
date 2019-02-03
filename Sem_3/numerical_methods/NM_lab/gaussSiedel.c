#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define Max 10
//---------------------------------------------------------------------


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
	if(fabs(c)<0.0001)
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

void check_existance(float a[Max][Max],int n)
{
	for(int i=0;i<n;i++)
	{
		max_swap(a,n,i);
		pivot(a,n,i);
	}
	return;
}


//---------------------------------------------------------------------




void check_convergence(float a[Max][Max], int n)
{
	for(int i=0;i<n;i++)
	{
		float sum=0;
		for(int j=0;j<n;j++)
			if(i!=j)
				sum+=fabs(a[i][j]);
		if(sum>fabs(a[i][i]))
		{
			printf("Condition for convergence not met! Diagonal elements are not dominant\n");
			exit(0);
		}
	}
	return;
}



//---------------------------------------------------------------------



//stores the values takig user input
void input(float a[Max][Max], float a1[Max][Max], int n)
{
	printf("Enter the matrix:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			scanf(" %f",&a[i][j]);
			a1[i][j]=a[i][j];
		}
	}
	return;
}


void print_roots(float *x, int n, int count, float err)
{
	//printf("\nThe solution is:\n");
	printf("%d\t\t",count);
	printf("%f\t", err);
	for(int i=0;i<n;i++)
		printf("%f ",x[i]);
	printf("\n");
}

float error_max(float *r, float *rold, int n)
{
	float max=0;
	for(int i=0;i<n;i++)
		if(max<fabs(r[i]-rold[i]))
			max=fabs(r[i]-rold[i]);
		
	
	return max;
}

int main()
{
	int n;
	printf("Enter the number of variables :");
	scanf("%d",&n);
	

	float a[Max][Max],a1[Max][Max];
	input(a,a1,n);
	
	//check_convergence(a,n);
	check_existance(a1,n);
	check_convergence(a,n);
	
	float r[n],rold[n];
	//initial guess
	for(int i=0;i<n;i++)
	{
		r[i]=1;
		rold[i]=4;
	}
	
	int count=0;
	int t=10;
	//while(t--)
	float err;
	
	printf("Ineration\tmax_error\tRoots\n");
	printf("------------------------------------------------\n");
	while(error_max(r,rold,n)>0.000001)
	{
		err=error_max(r,rold,n);
		count++;
		for(int i=0;i<n;i++)
		{
			rold[i]=r[i];
			r[i]=a[i][n];
			for(int j=0;j<n;j++)
				if(i!=j)
					r[i]-=a[i][j]*r[j];
			r[i]=r[i]/a[i][i];
		}
		print_roots(r,n,count,err);
	}
	
	print_roots(r,n,count,err);
	return 0;
}
