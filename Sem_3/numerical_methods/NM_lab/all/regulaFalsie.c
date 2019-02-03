#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define prcn 0.000001


//problem functions
//f(x)
double f(double x)
{
	return (x*x-x-6);
}
//standard functions used by methods
//order of convergence
double conv(double e2,double e1)
{
	return log(e2)/log(e1);
}
//absolute error
double error(double c1,double c2)
{
	return fabs(c1-c2);
}
//regula falsie
void rf(double a,double b)
{
	printf("\t\t\t\t\t\tRegula Falsie\n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("iternation\tlowerbound\tupperbound\tintersection-pont\tf(c)\t\terror\t\torder of convergence\n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	double cprev=a;
	double c=(a*f(b)-b*f(a))/(f(b)-f(a));
	double e1=error(c,cprev),e2;
	double oconv;
	int count=0;
	FILE *fp = fopen("./data/rf","w");
	while(fabs(e1)>prcn)
	{
		count++;
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
		e1=error(c,cprev);
		cprev=c;
		if(f(a)*f(c)<0)
		{
			c=(a*f(c)-c*f(a))/(f(c)-f(a));
			e2=error(c,cprev);
			oconv=conv(e2,e1);
			fprintf(fp,"%lf,%lf\n",oconv,e1);
			printf("%d\t\t%lf\t%lf\t%lf\t\t%lf\t%lf\t%lf\n",count,a,b,c,f(c),e2,oconv);
			b=c;
		}
		else
		{
			c=(c*f(b)-b*f(c))/(f(b)-f(c));
			e2=error(c,cprev);
			oconv=conv(e2,e1);
			fprintf(fp,"%lf,%lf\n",oconv,e1);
			printf("%d\t\t%lf\t%lf\t%lf\t\t%lf\t%lf\t%lf\n",count,a,b,c,f(c),e2,oconv);
			a=c;
		}
	}
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("Root : %lf\n\n\n\n",c);
}
int main()
{
	double a,b;
	a=0;
	b=-3;
	rf(a,b);
	return 0;
}
