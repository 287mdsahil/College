#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define Max 20

//stores the values takig user input---------------------------------------------------------------
void input(float a[Max][Max],float a1[Max][Max],int n)
{
	printf("Enter the matrix:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf(" %f",&a[i][j]);
			a1[i][j]=a[i][j];
		}
	}
	return;
}


//creats and identity matrix----------------------------------------------------------------------
void create_identity(float b[Max][Max], int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==j)
				b[i][j]=1;
			else
				b[i][j]=0;
	return;
}


//swaps the rows of a matrix-----------------------------------------------------------------------
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

//shifts the largest leading value of a row to the top and scales it to 1 -------------------------
void max_swap(float a[Max][Max], float b[Max][Max], int n,int i)
{
	int max=i;
	for(int i2=i;i2<n;i2++)
		if(a[i2][0]>a[max][0])
			max=i2;

	if(i!=max)
	{
		swap_rows(a,n,i,max);
		swap_rows(b,n,i,max);
	}
	
	float c=a[i][i];
	if(fabs(c)<0.00001)
	{
		printf("Inverse does not exist!\n");
		exit(0);
	}
	for(int j=0;j<=n;j++)
	{
		a[i][j]/=c;
		b[i][j]/=c;
	}
	return;
}

//performs elementry row pivot operations-------------------------------------------------------
void substract_row(float a[Max][Max], float b[Max][Max], int n, int x, int y)
{
	if(a[x][x]==0)
		return;

	float c=a[y][x]/a[x][x];
	for(int i=0;i<n+1;i++)
	{
		a[y][i]-=a[x][i]*c;
		b[y][i]-=b[x][i]*c;
	}
	
}



//performs the pivot operation-------------------------------------------------------------------
void pivot(float a[Max][Max], float b[Max][Max], int n, int i)
{
	for(int j=n-1;j>i;j--)
		substract_row(a,b,n,i,j);
	return;
}

//create a row echlon matric id lower triangle is zero-------------------------------------------
void echlon(float a[Max][Max], float b[Max][Max], int n)
{
	for(int i=0;i<n;i++)
	{
		max_swap(a,b,n,i);
		pivot(a,b,n,i);
	}
	return;
}

//prints the matrix-----------------------------------------------------------------------------
void printm(float a[Max][Max], int n)
{
	printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%f ",a[i][j]);
		printf("\n");
	}
	printf("\n");
	return;
}


void pivot2(float a[Max][Max], float b[Max][Max], int n, int i)
{
	for(int j=0;j<i;j++)
	{
		substract_row(a,b,n,i,j);
	}
	return;
}


void u_echlon(float a[Max][Max], float b[Max][Max], int n)
{
	for(int i=n-1;i>0;i--)
	{
		pivot2(a,b,n,i);
	}
	return;
}

int check_exist(float a[Max][Max], int n)
{
	for(int i=0;i<n;i++)
		if(fabs(a[i][i])<0.00001)
			return 0;
	return 1;
}


void check_identity_m(float a[Max][Max], float b[Max][Max], int n)
{
	float c[Max][Max];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			c[i][j]=0;
			for(int x=0;x<n;x++)
				c[i][j]+=a[x][j]*b[i][x];
		}
		
	printm(c,n);
	return;
}


//==============================================================================================
int main()
{
	int n;
	printf("Enter the size of the matrix (no of rows) :");
	scanf("%d",&n);
	

	float a[Max][Max],a1[Max][Max];
	input(a,a1,n);
	
	float b[Max][Max];
	create_identity(b,n);
	
	echlon(a,b,n);
	
	//printm(a,n);
	//printm(b,n);
	
	u_echlon(a,b,n);
	
	if(!check_exist(a,n))
	{
		printf("Inverse does not exist!\n");
		return 0;
	}
	
	//printm(a,n);
	printm(b,n);
	
	check_identity_m(a1,b,n);
	
	return 0;
}
