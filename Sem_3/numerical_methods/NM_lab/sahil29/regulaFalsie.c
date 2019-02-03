#include<stdio.h>
#include<math.h>

#define PI 3.1415926
int count;
//f(x)-----------------------------------------------------
double f(double x)
{
	return x*sin(x)+cos(x);
	//return x*x*x-18;
}

//rf method------------------------------------------------

double rf(double a, double b, double cprev)
{
	double c=(a*f(b)-b*f(a))/(f(b)-f(a));
	count++;
	double e=(cprev-c>=0)?(cprev-c):(c-cprev);
	//printing the fucntion value
	printf("%d\t%f\t%f\t%f\t%f\t%f\t",count,a,b,c,f(c),e);
	if((cprev-c)<=0.000001 && (cprev-c)>=-0.000001)
	{
		double order=log(e)/log(e);
		printf("%lf\n",order);
		return c;
	}
	else if(f(a)*f(c)<0)
	{
		double e2=(b-c>=0)?(b-c):(c-b);
		double order=log(e2)/log(e);
		printf("%f\n",order);
		//printf("%f %f\n",e2,e);
		return rf(a,c,b);
	}
	else
	{
		double e2=(a-c>=0)?(a-c):(c-a);
		double order=log(e2)/log(e);
		printf("%f\n",order);
		//printf("%f %f\n",e2,e);
		return rf(c,b,a);
	}	
}
//===========================================================
int main()
{
	double a=0,b=PI;
	count=0;
	double root=rf(a,b,a);
	//printf("%lf\n",root);
	return 0;
}
