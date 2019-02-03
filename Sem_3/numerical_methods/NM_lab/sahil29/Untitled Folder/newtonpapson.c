#include <stdio.h>
#include <math.h>
#define pi 3.1415926

//------------------functions------------------------------------

double f(double x){
	return x*x-x-6;
};
double ff(double x){
	return 2*x-1;
};

double fff(double x){
	return 2;
};

//-----------------------Common Functions---------------------------

double error(double a,double b){
	double error=a-b;
	if(error<0){error=-error;};
	return error;
};

double root(double m){
	if(f(m)==0){return m;}
	return 1234;
};

double convergence(double e1,double e2){
	double n;
	n=(log(e2)/log(e1));
	if(n<0){n=-n;};
	return n;
};
 
int checkconvo(x){
	double a;
	a=(f(x)*fff(x))/(ff(x)*ff(x));
	if (a<1){return 1;}
	else{return 0;};
};




//-------------------Newton Rapson Method--------------------

double newton(double r){
	return r-f(r)/ff(r);
};


void displaynewton(double* r0,double* r1,int i){
	double e0,e1;
	e0=newton(*r0)-*r0;
	e1=newton(*r1)-*r1;
	printf("%d\t",i);
	printf("%3.6f\t",*r0);
	printf("%3.6f\t",f(*r0));
	printf("%3.6f\t",error(fabs(e0),fabs(e1)));
	printf("%3.6f\t\n",convergence(fabs(e0),fabs(e1)));
	*r0=*r1;
	*r1=newton(*r0);
};


//--------------------Bisection Method-----------------------------

void changeBI(double* a,double* b){
	double m=(*a,*b)/2;
	if(f(*a)*f(m)<0){*b=m;}
	else if(f(*a)*f(m)>0){*a=m;};
};

void bisection(double a,double b){
	int count=1;
	while((b-a)>=0.000001){
		double e1,e2,m,con;
		m=(a+b)/2;
		e1=error(a,b);
		printf("%2d   ",count);
		printf("%1.6f   ",a);
		printf("%1.6f   ",b);
		printf("%1.6f   ",m);
		printf("%5.6f   ",f(m));
		printf("%1.6f   ",e1);
		count=count+1;
		if(root(m)!=1234){break;};
		changeBI(&a,&b);
		e2=error(a,b);
		con=convergence(e1,e2);
		printf("%1.6f   \n",con);
	};
};

//--------------------Regular Falsi Method---------------------------
double c(double a,double b){
	return (a*f(b)-b*f(a))/(f(b)-f(a));
}; 

void change(double* a,double* b){
	double m=c(*a,*b);
	if(f(*a)*f(m)<0){*b=m;}
	else if(f(*a)*f(m)>0){*a=m;};
};

void falsi(double a,double b){
	int count=1;
	double c1,c2,e1,e2,con;
	c1=a;
	c2=c(a,b);
	while((c2-c1)>=0.000001){
		e1=error(c1,c2);
		printf("%2d   ",count);
		printf("%1.6f   ",a);
		printf("%1.6f   ",b);
		printf("%1.6f   ",c2);
		printf("%5.6f   ",f(c2));
		printf("%1.6f   ",e1);
		count=count+1;
		if(root(c2)!=1234){break;};
		change(&a,&b);
		c1=c2;
		c2=c(a,b);
		e2=error(c1,c2);
		con=convergence(e1,e2);
		printf("%1.6f   \n",con);
	};
};

//------------------Secant Method-------------------------------------
double cc(double a,double b){
	return (a*f(b)-b*f(a))/(f(b)-f(a));
}; 


void displaysecant(double* r0,double* r1,int i){
	printf("%d\t",i);
	printf("%3.6f\t",*r0);
	printf("%3.6f\t",f(*r0));
	printf("%3.6f\t",error(fabs(*r0),fabs(*r1)));
	printf("%3.6f\t\n",convergence(abs(*r0),abs(*r1)));
	double dummy;
	dummy=*r0;
	*r0=*r1;
	*r1=cc(dummy,*r1);
};
//------------------Fixed Point Iteration Method----------------------
double g(double x){
	return sqrt(x+6);
};

//double gg(double x){
	
void iteration(double r0){
	double r1=g(r0);
	int i=0;
	while(fabs(r1-r0)>0.00005){
		printf("%d\t",i);
		printf("%3.6f\t",r0);
		printf("%3.6f\t",f(r0));
		printf("%3.6f\t",error(fabs(r0),fabs(r1)));
		printf("%3.6f\t\n",convergence(abs(r0),abs(r1)));
		r0=r1;
		r1=g(r1);
		i=i+1;
	};
};
//--------------------------------------------------------------------
int main(){
	/*printf("FUNCTION IS xsin(x)+cos(x)\n");
	
	//newton ralpson
	double r0,r1;
	int i;
	i=1;
	r0=pi;
	r1=newton(r0);
	printf("-----------------------------------------------\n");
	printf("---------------NEWTON RALPHSON METHOD------------\n");
	printf("Iteration\tRoot\tf(x)\tError\tRadius\n");
	while(fabs(r1-r0)>0.00005 && checkconvo(r0)){
		displaynewton(&r0,&r1,i);
		i=i+1;
	};
	
	
	//bisection and falsi
	double a,b,m;
	a=0;
	b=pi;
	/*
	printf("-----------------------------------------------\n");
	printf("---------------REGULA FALSI METHOD------------\n");
	printf("Iteration\tRoot\tf(x)\tError\tRadius\n");
	//bisection(a,b);*/
	//falsi(a,b);
	//printf("---------------------------------------------------------------------------------\n");
	
	
	//secant
	/*double r0,r1;
	int i;
	i=1;
	r0=0;
	r1=pi;
	while(fabs(r1-r0)>0.00005 && checkconvo(r0)){
		displaysecant(&r0,&r1,i);
		i=i+1;
	};*/
	
	//double r0=4;
	//iteration(r0);
	return 0;
};
	
		
		
	
	
	
	
	
	
	
	
	
	
	


