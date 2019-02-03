#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PRECISSION 0.000001

//fuction
float f(float x)
{
	float f=x*x*x*x-5*x*x*x+10*x*x-10*x+4;
	return f;
}


//stores the coefficients in an array
void coeff(float *a)
{
	//for the equation x*x*x*x-5*x*x*x+10*x*x-10*x+4;
	a[0]=4;
	a[1]=-10;
	a[2]=10;
	a[3]=-5;
	a[4]=1;
}


//stores the coefficients of the divident and the reminder
void coeff_b(float *b, float *a, float r, float s, int n)
{
	b[n]=a[n];
	b[n-1]=a[n-1] +r*b[n];
	
	for(int i=n-2;i>=0;i--)
		b[i] = a[i] + r*b[i+1] + s*b[i+2];
}


//calculates the value of d(b)/dr
void db_dr(float *dbdr, float *b, float r, float s, int n)
{
	dbdr[n]=0;
	dbdr[n-1]=b[n];
	
	for(int i=n-2;i>=0;i--)
		dbdr[i] = b[i+1] + r*dbdr[i+1] + s*dbdr[i+2];
}


//calculates the value of d(b)/ds
void db_ds(float *dbds, float *b, float r, float s, int n)
{
	dbds[n]=0;
	dbds[n-1]=0;
	
	for(int i=n-2;i>=0;i--)
		dbds[i] = r*dbds[i+1] + b[i+2] + s*dbds[i+2];
}

//updates the value of s
float update_s(float *b, float *dbdr, float *dbds,float r, float s)
{
	float ds = ( b[0]*dbdr[1] - b[1]*dbdr[0] ) / ( dbdr[0]*dbds[1] - dbdr[1]*dbds[0] );
	return (s + ds);
}

//updates the value of r
float update_r(float *b, float *dbdr, float *dbds,float r, float s)
{
	float dr = ( b[0]*dbds[1] - b[1]*dbds[0] ) / ( dbds[0]*dbdr[1] - dbds[1]*dbdr[0] );
	return (r + dr);
}


//calculates the roots from r and s
void roots(float r, float s, float *root)
{
	root[0] = ( r + pow((r*r + 4*s),0.5) )/2;
	root[1] = ( r - pow((r*r + 4*s),0.5) )/2;
}


//updates the value of coeffecients of a after division
void coeff_a(float *a,float *b,int *n)
{
	for(int i=0;i<=*n-2;i++)
		a[i]=b[i+2];
	*n-=2;
}


//checks if the roots are complex
int complex_roots(float r, float s)
{
	if((r*r+4*s)<0)
		return 1;
	else 
		return 0;
}

void display(float *a,int n)
{
	for(int i=n;i>=0;i--)
	{
		printf("(%f*x^%d) ",a[i],i);
		if(i!=0) printf("+ ");
	}
	printf("\n");
}

//===============================================================================================================================================
int main()
{
	int n=4;
	//stores the degree
	float a[n+1];
	coeff(a);
	
	
	//quotient polynomial x^2-rx-s
	//initial guess
	float r,s;
	
	
	
	float b[n+1];
	float dbdr[n+1];
	float dbds[n+1];
	
	int div=0;
	while(n>0)
	{
		r=0.5;s=0.5;
		coeff_b(b,a,r,s,n);
		
		div++;
		printf("\n\n\n---------------------------DIVISION %d-----------------------\n",div);
		printf("f(x) = ");
		display(a,n);
		printf("\n");
		
		if(n==2)
		{
			r=-a[1];
			s=-a[0];
			
			if(complex_roots(r,s))
			{
				printf("roots : ");
				float real=r/2;
				float img=sqrt(fabs(r*r+4*s))/2;
				printf("%f+i%f ",real,img);
				printf("%f-i%f ",real,img);
				printf("\n");
			}
			else
			{
				float root[2];
				roots(r,s,root);
				printf("roots : %f %f \n",root[0],root[1]);
			}
					
			break;
		}
		else if(n==1)
		{
			float root=-b[0]/b[1];
			printf("root : %f\n", root);
			break;
		}
		do
		{
				for(int i=n;i>=0;i--)
				{
					printf("%f\t",b[i]);
				}
				printf("\n");
		
			db_dr(dbdr,b,r,s,n);	
			db_ds(dbds,b,r,s,n);
	
			s=update_s(b,dbdr,dbds,r,s);
			r=update_r(b,dbdr,dbds,r,s);
		
		
			coeff_b(b,a,r,s,n);
			//printf("r=%f s=%f\n",r,s);
		}while(fabs(b[0])>PRECISSION && fabs(b[1])>PRECISSION);
		
		
		if(complex_roots(r,s))
		{
			printf("roots : ");
			float real=r/2;
			float img=sqrt(fabs(r*r-4*s))/2;
			printf("%f+i%f ",real,img);
			printf("%f-i%f ",real,img);
			printf("\n");
		}
		else
		{
			float root[2];
			roots(r,s,root);
			printf("roots : %f %f \n",root[0],root[1]);
		}
		
		
		if(n>2)
			coeff_a(a,b,&n);

	}	
	
	
	
	return 0;
}
