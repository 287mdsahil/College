#include<stdio.h>
#include<math.h>

float intf(float x){
    return (3*x*x*x*x/4 - x*x/2);
}

float f(float x){
    return (3*x*x*x - x);
}

float trapeziodal(float l,float u,int step){
	float h=(u-l)/step;
	float result=0;
	for(int i=0;i<step;++i){
		result=result+0.5*h*(f(l+(i+1)*h)+f(l+i*h));
	};
	return result;
};

int main(){
    printf("function: 3x^3 -x\n");
    float l,u;
    printf("Enter lower limit: ");
    scanf(" %f",&l);
    printf("Enter upper limit: ");
    scanf(" %f",&u);

    printf("Steps\tIntegrated value\terror\n");
    printf("---------------------------------------------------\n");
    for(int i=0;i<=10;i++){
        int steps=pow(2,i);
        float ans=trapeziodal(l,u,steps);
        printf("%d\t%f\t\t%f\n",steps,ans,fabs((intf(u)-intf(l))-ans));
    }
    return 0;
}