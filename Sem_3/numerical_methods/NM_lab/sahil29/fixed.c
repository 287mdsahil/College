#include<stdio.h>
#include<math.h>
int count=0;
//fixed point iteration--------------------------------------

double fp_f(double x)
{
	double cot=cos(x);
	cot/=sin(x);
	cot=-cot;
	return sqrt(x+6);
}

double fixedpoint(double x)
{
	double x2=fp_f(x);
	while(fabs(x2-x)>0.0001)
	{
		//printf("%lf\t%lf\t%lf\n",x,x2,fabs(x2-x));
		//printf("%lf\n",x);
		double eprev=fabs(x2-x);
		x=x2;
		x2=fp_f(x2);
		count++;
		double e=fabs(x2-x);
		double oconv=log(e)/log(eprev);
		printf("%d\t%lf\t%lf\t%lf\n",count,x,e,oconv);
	}
	return x2;
}


int main()
{
	count=0;
	double a=0;
	double root=fixedpoint(a);
	return 0;
}
