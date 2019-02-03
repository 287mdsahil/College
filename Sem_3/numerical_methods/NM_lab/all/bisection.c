#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define prcn 0.000001


//problem functions============================================================
//f(x)-------------------------------------
double f(double x)
{
	return (x*x-x-6);
}
//==============================================================================



//standard functions used by methods============================================
//order of convergence------------------------
double conv(double e2,double e1)
{
	return log(e2)/log(e1);
}
//absolute error------------------------------
double error(double c1,double c2)
{
	return fabs(c1-c2);
}
//==============================================================================

//bisection method-----------------------------
void bisection(double a, double b)
{
	printf("\t\t\t\t\t\tBisection Method\n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("iternation\tlowerbound\tupperbound\tmid-point\tf(c)\t\terror\t\torder of convergence\n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	
	int count=0;
	double mid;
	double e1,e2;
	double oconv;
	double new;
	FILE *fp = fopen("./data/bisection","w");
	
	while(fabs(a-b)>prcn)
	{
		e1=error(a,b);
		mid=(a+b)/2;
		if(f(a)*f(mid)<0)
		{	
			e2=error(a,mid);
			oconv=conv(e2,e1);
			count++;
			fprintf(fp,"%lf,%lf\n",oconv,e1);
			printf("%d\t\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",count,a,b,mid,f(mid),e1,oconv);
			b=mid;
		}
		else
		{
			e2=error(mid,b);
			oconv=conv(e2,e1);
			count++;
			fprintf(fp,"%lf,%lf\n",oconv,e1);
			printf("%d\t\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",count,a,b,mid,f(mid),e1,oconv);
			a=mid;
		}
	}
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("Root : %lf\n\n\n\n",mid);
}

//================================================================================================

int main()
{
	double a,b;
	a=0;
	b=-3;
	bisection(a,b);
	return 0;
}




