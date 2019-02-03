#include <stdio.h>
#include <string.h>
#include <math.h>

//GET THE NAME OF THE STUDENT BY PASSING ROLL	
void getname(int roll,char name[26]){
	FILE* fp;
	fp=fopen("1.5.names","r");
	for(int i=0;i<roll;++i){
		fgets(name,26,fp);
	};
};

//RETURNS THE NUMBER OF DIGITS IN A INTEGER
int length(int n){
	int len=0;
	while(n>0){n=n/10;len=len+1;};
	return len;
};

//REVERSE A NUMBER
int rev(int n){
	int num=0;
	while(n>0){
		num=num*10+n%10;
		n=n/10;
	};
	return num;
};

//PRINTS THE LONG INTEGER FORMED FROM THE NAME
void printinteger(int roll,int longint[100],int* namelength){
	char name[26];
	int x,len;
	int k=0;

	getname(roll,name);
	printf("%s",name);
	for(int i=0;name[i]!='\n';++i){
		x=name[i];
		if(name[i]!=' '){
			printf("%d",x);
			len=length(x);
			*namelength=*namelength+len;
			x=rev(x);
			for(int j=0;j<len;++j,x=x/10,k=k+1){
				longint[k]=x%10;
			};
			
		};
	};
	printf("\n");
};

//DIVIDING THE LONG INTEGER INTO TWO HALVES AND ADDING THEM
long long int divadd(int longint[100],int namelength){
	long long int h1=0;
	long long int h2=0;
	for(int i=0;i<namelength/2;++i){
		h1=h1*10+longint[i];
	};
	for(int i=namelength/2;i<namelength;++i){
		h2=h2*10+longint[i];
	};
	return h1+h2;
};

//COMPUTING REMAINDERS AND STORING IN TEXT FILE
void primediv(long long int num){
	FILE* fp1;
	FILE* fp2;
	fp1=fopen("1.7.primes","r");
	fp2=fopen("1.7.reminders","w");
	int prime;
	for(int i=0;i<1061;++i){
		fscanf(fp1,"%d\n",&prime);
		fprintf(fp2,"%lld\n",num%prime);
	};
	fclose(fp1);
	fclose(fp2);
};
		
//MAIN PROGRAM
int main(){
	int roll;
	int longint[100];
	int namelength=0;
	long long int num;
	printf("ENTER YOUR ROLL NUMBER: ");
	scanf("%d",&roll);
	printinteger(roll,longint,&namelength);
	num=divadd(longint,namelength);
	primediv(num);
	return 0;
};

