#include <stdio.h>
#define size 1000
void display_all(void);
void display(int);

//STRUCTURE REPRESENTING A TERM
struct term{
	int exp;
	float coef;
};
struct term term_pool[size];  //STORES ALL THE TERMS
int poly_pool[size];          //STORES ENDING INDEX OF EACH POLYNOMIAL IN THE TERM POOL

int index1=0;  //COUNTER FOR TERMPOOL INDEX
int index2=0;  //COUNTER FOR POLY POOL INDEX

int empty(int start,int end){
	if(start==end){return 1;}
	else{return 0;};
};

//--------------------FUNCTIONS---------------------------------------------------------------

//FUNCTION TO ADD TWO POLYNOMIALS
void add(int p1,int p2){
	int start1,end1;
	if(p1==1){start1=0;end1=poly_pool[0];}
	else{start1=poly_pool[p1-2]+1;end1=poly_pool[p1-1];};

	int start2,end2;
	if(p2==1){start2=0;end2=poly_pool[0];}
	else{start2=poly_pool[p2-2]+1;end2=poly_pool[p2-1];};
	
	int check[size];    //STORES EXPONENTS ALREDY COVERED
	int count=0;
	for(int i=start1;i<end1+1;++i){
		struct term t1;
		struct term t3;
		struct term t2;
		int flag=0;
		t1=term_pool[i];
		for(int j=start2;j<end2+1;++j){
			t2=term_pool[j];
			if(t1.exp==t2.exp){
				t3.exp=t1.exp;
				t3.coef=t1.coef+t2.coef;
				flag=1;
				term_pool[index1]=t3;
				index1++;
				check[count]=t1.exp;
				count++;
			};
		};
		if(flag==0){term_pool[index1]=t1;index1++;}
	};
	
	for(int j=start2;j<end2+1;++j){
		struct term t2;
		t2=term_pool[j];
		int flag=0;
		for(int i=0;i<count;++i){
			if(t2.exp==check[i]){flag=1;}
		};
		if(flag==0){term_pool[index1]=t2;index1++;};
	};
	poly_pool[index2]=index1-1;
	index2++;
	printf("-----------------------------------------------------------------\n");
	display(index2);
	printf("-----------------------------------------------------------------\n");

};

//FUNCTION TO MULTIPLY A CONSTANT TO A POLYNOMIAL
void mulc(int p1,float c){
	int start,end;
	if(p1==1){start=0;end=poly_pool[0];}
	else{start=poly_pool[p1-2]+1;end=poly_pool[p1-1];};

	for(int i=start;i<end+1;++i){
		struct term t1;
		struct term t2;
		t1=term_pool[i];
		t2.exp=t1.exp;
		t2.coef=(t1.coef)*c;
		term_pool[index1]=t2;
		index1++;
	};
	poly_pool[index2]=index1-1;
	index2++;
	printf("-----------------------------------------------------------------\n");
	display(index2);
	printf("-----------------------------------------------------------------\n");
};

//FUNCTION TO SUBTRACT ONE POLYNOMIAL FROM ANOTHER (P1-P2)
void sub(int p1,int p2){
	mulc(p2,-1);
	p2=index2;
	add(p1,p2);
	//display(index2);
};

//FUNCTION TO MULTIPLY TWO POLYNOMIALS	
void mul(int p1,int p2){
	int start1,end1;
	if(p1==1){start1=0;end1=poly_pool[0];}
	else{start1=poly_pool[p1-2]+1;end1=poly_pool[p1-1];};

	int start2,end2;
	if(p2==1){start2=0;end2=poly_pool[0];}
	else{start2=poly_pool[p2-2]+1;end2=poly_pool[p2-1];};
	
	struct term t1;
	struct term t2;
	struct term t3;
	t1=term_pool[start1];
	for(int j=start2;j<end2+1;++j){	
		t2=term_pool[j];
		t3.exp=t1.exp+t2.exp;
		t3.coef=t1.coef*t2.coef;
		term_pool[index1]=t3;
		index1++;
	};
	poly_pool[index2]=index1-1;
	index2++;

	for(int i=start1+1;i<end1+1;++i){
		struct term t1;
		struct term t2;
		struct term t3;
		t1=term_pool[i];
		for(int j=start2;j<end2+1;++j){	
			t2=term_pool[j];
			t3.exp=t1.exp+t2.exp;
			t3.coef=t1.coef*t2.coef;
			term_pool[index1]=t3;
			index1++;
		};
		poly_pool[index2]=index1-1;
		index2++;
		add(index2,index2-1);
	};
	//display(index2);
};

//FUNCTION TO CHECK IF POLYNOMIAL IS 0
int zero(int p1){
	int start,end;
	if(p1==1){start=0;end=poly_pool[0];}
	else{start=poly_pool[p1-2];end=poly_pool[p1-1];};

	for(int i=start;i<end+1;++i){
		if(term_pool[i].coef>0.000001){return 0;};
	};
	return 1;
};

//FUNCTION TO RETURN DEGREE OF POLYNOMIAL
int deg(int p1){
	int start,end;
	if(p1==1){start=0;end=poly_pool[0];}
	else{start=poly_pool[p1-2];end=poly_pool[p1-1];};
	
	int max=0;
	for(int i=start;i<end+1;++i){
		if(term_pool[i].exp>max){max=term_pool[i].exp;};
	};
	return max;
};

//FUNCTION TO DISPLAY A POLYNOMIAL
void display(int p1){
	int start,end;
	if(p1==1){start=0;end=poly_pool[0];}
	else{start=poly_pool[p1-2]+1;end=poly_pool[p1-1];};
	
	for(int i=start;i<end+1;++i){
		int exp_;
		float coef_;
		exp_=term_pool[i].exp;
		coef_=term_pool[i].coef;
		printf("+(%f).X^(%d) ",coef_,exp_);
	};
	printf("\n");
};


void display_all(){
	printf("THE FOLLOWING POLYNOMIALS ARE AVAIALABLE:\n");
	printf("-------------------------------------------------------------------\n");
	for(int i=0;i<index2;++i){
		printf("%d. ",i+1);
		display(i+1);
	};
	printf("-------------------------------------------------------------------\n");
};


//--------------------ENTERING POLYNOMIALS----------------------------------------------------

int checkunique(int check[size],int exp_,int count){
	for(int i=0;i<count;++i){
		if (check[i]==exp_){return 0;}
	};
	return 1;
};

void read_poly(void){
	int n;
	printf("ENTER NUMBER OF TERMS OF POLYNOMIAL: ");
	scanf("%d",&n);

	printf("\nALERT!\nEACH TERM OF A POLYNOMIAL MUST HAVE DISTINCT EXPONENT\n");
	int check[size];   //USED TO CHECK IF USER IS MAINTAINING ABOVE CRITERIA
	int count=0;
	int flag=0;

	printf("-----------------------------------------------------------------\n");
	for(int i=0;i<n;++i){
		struct term t;
		int exp_,coef_;

		printf("ENTER EXPONENT: ");   //CHECKS IF USER ENTERED INTEGER VALUES AS EXPONENTS
		if(scanf("%d",&exp_)){
			if(exp_<0){printf("EXPONENTS MUST BE POSITIVE INTEGERS\n");return;}; //CHECKS IF EXPONENT IS POSITIVE
			if(checkunique(check,exp_,count)){check[count]=exp_;count++;}  //CHECKS IF EXPONENT ENTERED IS UNIQUE
			else{printf("EXPONENT ALREDY ENTERED\n");continue;};
		}
		else{
			printf("EXPONENTS MUST BE INTERGERS\n");
			break;
		};

		printf("ENTER COEFFICIENT: ");
		scanf("%d",&coef_);
		printf("-----------------------------------------------------------------\n");

		t.exp=exp_;
		t.coef=coef_;
		term_pool[index1]=t;
		index1=index1+1;
		flag=1;
	};

	if(flag==1){
		poly_pool[index2]=index1-1;
		index2=index2+1;
	};
};
//-------------------------MENU OF FUNCTIONS--------------------------------------------
void menu(){
	display_all();
	int choice;
	printf("\nCHOOSE AN OPTION BY PRESSING:\n1. ADD TWO POLYNOMIALS\n2. SUBTRACT 1 POLYNOMIAL FROM ANOTHER\n3. MULTIPLY TWO POLYNOMIALS\n4. MULTIPLY A POLYNOMIAL WITH A CONSTANT\n");
	printf("5. CHECK IF POLYNOMIAL IS 0\n6. FIND DEGREE OF A POLYNOMIAL\n7. DISPLAY A POLYNOMIAL\n");
	scanf("%d",&choice);
	
	int p1,p2;
	float c;
	if(choice==4 ||choice==5 ||choice==6 ||choice==7){
		printf("ENTER POLYNOMIAL NUMBER :");
		scanf("%d",&p1);
	}
	else{printf("ENTER POLYNOMIAL NUMBERS :");scanf("%d %d",&p1,&p2);};

	switch(choice){
		case 1: add(p1,p2);
			break;
		case 2: sub(p1,p2);
			break;
		case 3: mul(p1,p2);
			break;
		case 4: printf("ENTER CONSTANT :");
			scanf("%f",&c);
			mulc(p1,c);
			break;
		case 5: if(zero(p1)){printf("ZERO POLYNOMIAL\n");}else{printf("NOT ZERO\n");};
			break;
		case 6: printf("DEGREE: %d",deg(p1));
			break;
		case 7: display(p1);
			break;
	};
};		
//--------------------------MAIN FUNCTION-----------------------------------------------------
int main(){
	while(1){
		int choice;
		printf("\nPRESS 0 TO EXIT\nPRESS 1 TO ENTER A POLYNOMIAL\nPRESS 2 TO DISPLAY FUNCTION MENU\n");
		scanf("%d",&choice);
		
		if(choice==0){break;}
		else if(choice==1){read_poly();}
		else{menu();};
	};
	return 0;
}
