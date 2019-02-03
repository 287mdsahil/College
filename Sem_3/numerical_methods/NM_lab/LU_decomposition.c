#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Max 10


void inputMatrix(float a[Max][Max],int *n)
{
	printf("Enter the size of the square matrix: ");
	scanf("%d",n);
	
	//taking input for the matrix
	printf("Enter the argumented matrix:\n");
	for(int i=0;i<*n;i++)
		for(int j=0;j<=*n;j++)
			scanf("%f",&a[i][j]);
	return;
}

//print a matrix
void printm(float a[Max][Max], int n)
{
	//printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%f ",a[i][j]);
		printf("\n");
	}
	printf("\n");
	return;
}


void LU_decomposition(float a[Max][Max],float l[Max][Max],float u[Max][Max], int n)
{
	//initialize with all zero
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{l[i][j]=0;u[i][j]=0;}

	
	for(int i=0;i<n;i++)
	{	
		for(int j=i;j<n;j++)
		{
			float sum=0;
			for(int k=0;k<i;k++)
				sum+=l[i][k]*u[k][j];
			
			u[i][j]=a[i][j]-sum;
		}
		
		
		
		for(int j=i;j<n;j++)
		{
			if(i==j)
				l[i][j]=1;
			else
			{
				float sum=0;
				for(int k=0;k<n;k++)
					sum+=l[j][k]*u[k][i];
			
				l[j][i]=(a[j][i]-sum)/u[i][i];
			}
		}
	}
	

	return;
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
	//for(int j=0;j<=n;j++)
	//	a[i][j]/=c;
	
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

int main()
{
	int n;
	float a[Max][Max];
	inputMatrix(a,&n);
	
	float l[Max][Max],u[Max][Max];
	LU_decomposition(a,l,u,n);
	
	printf("\n");
	printf("lower triangular matrix: \n");
	printm(l,n);
	printf("upper triangular matrix: \n");
	printm(u,n);
	
	echlon(a,n);
	
	printm(a,n);
	
	//hehe
	for(int i=0;i<n;i++)
		u[i][n]=a[i][n];
		
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(u[i][i]==0)
		{
			printf("Infinite or no solution\n");
			flag=1;
			break;
		}
	}
	if(flag)
		return 0;
	
	float x[n];
	roots(u,x,n);
	print_roots(x,n);
	
	return 0;
}
