#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Max 10
#define Prcn 0.000001


//==========================================================inputs

int input_size()
{
	printf("Enter the size of the matrix: ");
	int n;
	scanf("%d",&n);
	return n;
}

//-----------------------------------------------------------------

void input_matrix(float a[Max][Max], int n)
{
	printf("Enter the matrix:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%f",&a[i][j]);
	return;
}

//======================================================power-method

void genInitialGuess(float *x,int n, float value)
{
	for(int i=0;i<n;i++)
		x[i]=value;
	return;
}

//------------------------------------------------------------------

void arrayCopy(float *v1, float *v2, int n)
{
	for(int i=0;i<n;i++)
		v1[i]=v2[i];
	return;
}

//------------------------------------------------------------------
void matrixMultiply(float a[Max][Max], float *v, float *x, int n)
{
	arrayCopy(v,x,n);
	genInitialGuess(x,n,0);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			x[i]+=a[i][j]*v[j];
	return;
}
//------------------------------------------------------------------

float largestCoeff(float *v, int n)
{
	int max=0;
	for(int i=0;i<n;i++)
		if(fabs(v[i])>fabs(v[max]))
			max=i;
	return v[max];
}

//------------------------------------------------------------------

void printResult(float c, float cold, float *v, int n)
{
	printf("--------------------------\n");
	printf("Eigen value: %f\n",c);
	float rateOfConv = cold/c;
	printf("Rate of Convergence: %f\n",rateOfConv);
	printf("Eigen Vector:\n");
	for(int i=0;i<n;i++)
		printf("%f\n",v[i]);
	//printf("--------------------------\n");
	return;
}
//------------------------------------------------------------------

void scalarDivide(float c, float *v, int n)
{

	for(int i=0;i<n;i++)
		v[i]=v[i]/c;
	return;
}
//------------------------------------------------------------------

int accuCheck(float *x, float *v, int n)
{
	for(int i=0;i<n;i++)
		if(fabs(x[i]-v[i])>Prcn)
			return 0;
	return 1;
}

//------------------------------------------------------------------

void power(float a[Max][Max], int n)
{
	float x[n];
	if(n==2)
	{
		x[0]=1;x[1]=0;
	}
	else
		genInitialGuess(x,n,1);
	
	float v[n];
	
	float cold=0,c=1;
	
	do
	{
		matrixMultiply(a,v,x,n);
		cold=c;
		c = largestCoeff(x,n);
		//==========
		printResult(c,cold,x,n);
		scalarDivide(c,x,n);
	}
	while(!accuCheck(x,v,n));
	//printResult(c,v,n);
	return;
}

//==============================================================main
int main()
{
	int n = input_size();
	float a[n][n];
	input_matrix(a,n);
	power(a,n);
	return 0;
}
