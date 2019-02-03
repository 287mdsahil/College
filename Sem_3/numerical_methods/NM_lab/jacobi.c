#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Max 10


void inputMatrix(float a[Max][Max], int *n)
{
	printf("Enter the size of the square matrix: ");
	scanf("%d",n);
	printf("Enter the symmetric matrix:\n");
	int i,j;
	for(i=0;i<*n;i++)
		for(j=0;j<*n;j++)
			scanf("%f",&a[i][j]);
	return;
}
//------------------------------------------------------------------------------------

void max_coeff(float a[Max][Max], int n, int *r, int *s)
{
    int i,j;
	*r=0;
	*s=1;
	float max=a[0][1];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		if(i!=j)
		{
			if(fabs(a[i][j])>fabs(max))
			{
				max=a[i][j];
				(i<j)?(*s=j,*r=i):(*s=i,*r=j);
				//printf("%d %d %d %d\n",i,j,*r,*s);
			}	
		}
	return;
}

//------------------------------------------------------------------------------------
int sgn(float x)
{
	if(x>0)	return 1;
	else if(x==0)	return 0;
	else return -1;
}

void sin_cos(float a[Max][Max], int n, int r, int s, float *sinx,float *cosx)
{
	float A=2*a[r][s]*sgn(a[r][r]-a[s][s]);
	float B=fabs(a[r][r]-a[s][s]);
	float C=sqrt(A*A+B*B);
	
	*cosx=sqrt(0.5*(1+B/C));
	*sinx=A/(2*(*cosx)*C);
}
//------------------------------------------------------------------------------------
void a_new(float a[Max][Max], int n, int r, int s)
{
	float an[n][n];
	//float x=2*atan(2*a[r][s]/(a[r][r]-a[s][s]));
	
	float sinx,cosx;
	sin_cos(a,n,r,s,&sinx,&cosx);
	
	printf("sin:%f cos:%f\n",sinx,cosx);

    	int i,j;
	for(i=0;i<n;i++)
		if(i!=r && i!=s)
		{
			an[i][r]=a[i][r]*cosx+a[i][s]*sinx;
			an[r][i]=a[i][r]*cosx+a[i][s]*sinx;
			an[i][s]=-a[i][r]*sinx+a[i][s]*cosx;
			an[s][i]=-a[i][r]*sinx+a[i][s]*cosx;
		}

	an[r][r]=a[r][r]*cosx*cosx+2*a[r][s]*sinx*cosx+a[s][s]*sinx*sinx;
	an[s][s]=a[s][s]*cosx*cosx-2*a[r][s]*sinx*cosx+a[r][r]*sinx*sinx;

	an[r][s]=an[s][r]=0;


	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=r && i!=s && j!=r && j!=s)
				an[i][j]=a[i][j];
				
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=an[i][j];

	return;
}
//------------------------------------------------------------------------------------

void printm(float a[Max][Max], int n)
{
	printf("\n\n\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%f ",a[i][j]);
		printf("\n");
	}
}

//====================================================================================
int main()
{
	int n;
	float a[Max][Max];
	inputMatrix(a,&n);
	
	int t=4;
	while(t)
	{
		int r,s;
		max_coeff(a,n,&r,&s);

		//printf("\n\n\nr=%d s=%d : %f\n",r,s,a[r][s]);

		if(fabs(a[r][s])<=0.001)
			break;

		a_new(a,n,r,s);
		printm(a,n);
	}
	printf("\n\nTHE EIGENVALUES ARE:\n");
    int i;
	for(i=0;i<n;i++)
		printf("%f ",a[i][i]);
	printf("\n");

	return 0;
}
