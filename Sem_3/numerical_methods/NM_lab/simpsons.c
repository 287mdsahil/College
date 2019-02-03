#include<stdio.h>
#include<math.h>

float intf(float x){
    return (3*x*x*x*x/4 - x*x/2);
}

float f(float x){
    return (3*x*x*x - x);
}

float simpsons(float l,float u,int step){
	float h=(u-l)/step;
	float result=0;
	for(int i=0;i<=step;++i){
        if(i==0 || i==step-1)
            result+=f(l+i*h);
        else if(i%2==0)
            result+=4*f(l+i*h);
        else 
            result+=2*f(l+i*h);
	};
    result=result*h/3;
	return result;
};

int main(){
    printf("function: 3x^3 -x\n");
    float l,u;
    printf("Enter lower limit: ");
    scanf(" %f",&l);
    printf("Enter upper limit: ");
    scanf(" %f",&u);

    printf("Steps\tIntegrated value\t\terror\n");
    printf("---------------------------------------------------\n");
    for(int i=0;i<=12;i++){
        int steps=pow(2,i);
        float ans=simpsons(l,u,steps);
        printf("%d\t%f\t\t%f\n",steps,ans,fabs((intf(u)-intf(l))-ans));
    }
    return 0;
}