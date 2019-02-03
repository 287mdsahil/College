#include<stdio.h>
#include<math.h>

#define PI 3.1415926
int count;
//f(x)-----------------------------------------------------
float f(float x)
{
	return x*sin(x)+cos(x);
}

//bisection method-----------------------------------------

float bisection(float a, float b)
{
	float mid=(a+b)/2;
	count++;
	float e=(a-b>=0)?(a-b):(b-a);
	//printing the fucntion value
	printf("%d\t%f\t%f\t%f\t%f\t%f\t",count,a,b,mid,f(mid),e);
	if((a-b)<=0.000001 && (a-b)>=-0.000001)
	{
		float order=log(e)/log(e);
		printf("%lf\n",order);
		return mid;
	}
	else if(f(a)*f(mid)<0)
	{
		float e2=(a-mid>=0)?(a-mid):(mid-a);
		float order=log(e2)/log(e);
		printf("%lf\n",order);
		return bisection(a,mid);
	}
	else
	{
		float e2=(b-mid>=0)?(b-mid):(mid-b);
		float order=log(e2)/log(e);
		printf("%f\n",order);
		return bisection(mid,b);
	}	
}
//=========================================================
int main()
{
	float a=0,b=PI;
	count=0;
	float root=bisection(a,b);
	printf("%lf\n",root);
	return 0;
}
