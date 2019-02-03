#include<stdio.h>
#include<math.h>
float f(float x,float y){
    //return x+2*y;
    return y-x;
}
float fun(float x){
    return x+1-exp(x)/2;
}
int main(){
    //float y0=0,x0=0;
    float y0=0.5,x0=0;
    //float h=0.25; 
    float h=0.1;
    float xp=1;
    
    printf("Finding the value of y(1) given that y(0)=0.5, and y'=y-x\n\n");

	printf("Using euler method\n");
    float y,yprev=y0;
    int n=(xp-x0)/h;
    printf("x\t\ty\t\ty'\t\terror\n");
    for(int i=0;i<n;i++){
        y=yprev+h*f((x0+i*h),yprev);
        printf("%f\t%f\t%f\t%f\n",(x0+(i+1)*h),y,f((x0+i*h),yprev),y-fun(x0+(i+1)*h));
        yprev=y;
    }
    printf("ans: %f\n",y);

    printf("\n");
    
	printf("Using modified euler method\n");
    yprev=y0;
    y=0;
    printf("x\t\ty\t\ty'\t\terror\n");
    
    for(int i=0;i<n;i++){
        float yp=yprev+h*f((x0+i*h),yprev);
        y=yprev+h*(f((x0+(i+1)*h),yp)+f((x0+i*h),yprev))/2;
        printf("%f\t%f\t%f\t%f\n",(x0+(i+1)*h),y,f((x0+i*h),yprev),y-fun(x0+(i+1)*h));
        yprev=y;
    }
    printf("ans: %f\n",y);
    return 0;
}

