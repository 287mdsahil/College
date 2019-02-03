#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.1415926
int count=0;
//f(x)-----------------------------------------------------
double f1(double x)
{return x*x-2;}

double f11(double x)
{return 2*x;}

double f2(double x)
{return x*x*x-2*x-5;}

double f22(double x)
{return 3*x*x-2;}

double f3(double x)
{return x-2+log(x);}

double f33(double x)
{return 1+1/x;}

double f4(double x)
{return x*x*x-3*x-5;}

double f44(double x)
{return 3*x*x-3;}

double f5(double x)
{return x*sin(x)+cos(x);}

double f55(double x)
{return x*cos(x);}

double f555(double x)
{return cos(x)-x*sin(x);}

//error----------------------------------------------------
double error(double r,double rold)
{return (r-rold>=0)?(r-rold):(rold-r);}

//order of convergence-------------------------------------
double oconv(double e1,double e2)
{return log(e2/e1);}

//function------------------------------------------------
double f(double x)
{return f5(x);}

double fdx(double x)
{return f55(x);}

double fddx(double x)
{return f555(x);}


double rf(double a, double b, double cprev)
{
	double c=(a*f(b)-b*f(a))/(f(b)-f(a));
	count++;
	double e=(cprev-c>=0)?(cprev-c):(c-cprev);
	//printing the fucntion value
	printf("%d\t\t%f\t%f\t%f\t\t%f\t%f\t",count,a,b,c,f(c),e);
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


//bisection method-----------------------------------------

double bisection(double a, double b)
{
	double mid=(a+b)/2;
	count++;
	double e=(a-b>=0)?(a-b):(b-a);
	//printing the fucntion value
	printf("%d\t\t%f\t%f\t%f\t%f\t%f\t",count,a,b,mid,f(mid),e);
	if((a-b)<=0.000001 && (a-b)>=-0.000001)
	{
		double order=log(e)/log(e);
		printf("%lf\n",order);
		return mid;
	}
	else if(f(a)*f(mid)<0)
	{
		double e2=(a-mid>=0)?(a-mid):(mid-a);
		double order=log(e2)/log(e);
		printf("%lf\n",order);
		return bisection(a,mid);
	}
	else
	{
		double e2=(b-mid>=0)?(b-mid):(mid-b);
		double order=log(e2)/log(e);
		printf("%f\n",order);
		return bisection(mid,b);
	}	
}


//newton ralphson-----------------------------------------



int conv_cond(double x)
{
	double c=fabs(f(x)*fddx(x)/(fdx(x)*fdx(x)));
	//c=(c>0)?c:(-c);
	//printf("%f\n",c);
	
	if(c<1)
		return 1;
	else 
		return 0;
}

double nr()
{	
	double r=PI,rold=0;
	int iter=0;
	double oc;
	
	printf("-------------------------------------------------------------------\n");
	double e=(r-rold>=0)?(r-rold):(rold-r),eold;
	printf("iteration\troot\t\terror\t\torder of convergence\n");
	printf("-------------------------------------------------------------------\n");
	while(abs(e>0.0000001))
	{
		if(!conv_cond(r))
		{
			printf("condition for convergence not statisfied");
			break;
		}
		eold=(r-rold>=0)?(r-rold):(rold-r);
		//printf("%f\t%f\n",eold,r);
		rold=r;
		r=rold-f(rold)/fdx(rold);
		iter++;
		e=(r-rold>=0)?(r-rold):(rold-r);
		oc=oconv(e,eold);
		
		//printf("%f\t%f\t%f\n",eold,r,rold);
		printf("%d\t\t%f\t%f\t%f\n",iter,r,e,oc);
	}
	printf("-------------------------------------------------------------------\n");
	return r;
}
//=========================================================
int main()
{	
	printf("\n\nNewton Ralphson\n");
	nr();
	
	
	
	printf("\n\nRegula Falsie\n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("iternation\tlowerbound\tupperbound\tintersection-pont\tf(c)\t\terror\t\torder of convergence\n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	double a=0,b=PI;
	count=0;
	rf(a,b,a);
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	
	
	
	printf("\n\nBisection Method\n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("iternation\tlowerbound\tupperbound\tmid-point\tf(c)\t\terror\t\torder of convergence\n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	a=0,b=PI;
	count=0;
	bisection(a,b);
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	
	
	return 0;
}
