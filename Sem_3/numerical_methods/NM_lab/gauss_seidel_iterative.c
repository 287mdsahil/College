#include <stdio.h>
#include <math.h>
#define size 10

//----------------------------------------------------------------------------------------------------
//READS EQUATION INTO MATRIX FORM
void read_matrix(float a[size][size],float b[size],int n){
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("ENTER COEFFICIENT %d OF LINEAR EQUATION NO.%d :",j+1,i+1);
			scanf("%f",&a[i][j]);
		};
		printf("ENTER CONSTANT TERM OF LINEAR EQUATION %d:",i+1);
		scanf("%f",&b[i]);
		printf("-------------------------------------------------------------------------\n");
	};
};

//SETS INITIAL APPROXIMATION
void get_init(float x[size],int n){
	int i,j;
	for(i=0;i<n;++i){
		x[i]=0;
	};
};

//DISPLAYS AN ARRAY
void display(float x[size],int n){
	for(int i=0;i<n;++i){
		printf("%6.3f\t",x[i]);
	};
};

//----------------------------------------------------------------------------------------------------
//CALCULATES SUM UPTO A RANGE
float sum(float a[size][size],float x[size],int start,int end,int i){
	float sum=0;
	for(int j=start;j<end;++j){
		sum=sum+a[i][j]*x[j];
	};
	return sum;
};

//GENERATES THE VALUES OF Xi
float x_gen(float a[size][size],float b[size],float x[size],int n,int i){
	return (b[i]-sum(a,x,0,i,i)-sum(a,x,i+1,n,i))/a[i][i];
};

void fill_old(float x_old[size],float x[size],int n){
	for(int i=0;i<n;++i){
		x_old[i]=x[i];
	};
};

float max_diff(float x_old[size],float x[size],int n){
	float max=0;
	for(int i=0;i<n;++i){
		if(fabs(x[i]-x_old[i])>max){
			max=fabs(x[i]-x_old[i]);
		};
	};
	return max;
};

	
//CALCULATES THE VALUES OF VARIABLES
void gauss_seidel(float a[size][size],float b[size],float x[size],int n){
	int count=1;
	float diff;
	float x_old[size];
	fill_old(x_old,x,n);
	for(int i=0;i<n;++i){
			x[i]=x_gen(a,b,x,n,i);
	};
	diff=max_diff(x_old,x,n);
	while(diff>0.0001){
		printf("%d\t",count);
		display(x,n);
		printf("\n");
		count=count+1;
		fill_old(x_old,x,n);
		for(int i=0;i<n;++i){
			x[i]=x_gen(a,b,x,n,i);
		};
		diff=max_diff(x_old,x,n);
		
	};
};

//----------------------------------------------------------------------------------------------------

//MAIN FUNCTION
int main(){
	int n;
	float a[size][size];
	float b[size];
	float x[size];
	
	printf("ENTER SIZE OF MATRIX: ");
	scanf("%d",&n);
	read_matrix(a,b,n);
	get_init(x,n);
	
	gauss_seidel(a,b,x,n);
	return 0;
};
	
