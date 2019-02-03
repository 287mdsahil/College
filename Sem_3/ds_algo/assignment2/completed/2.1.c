#include<stdio.h>
#include<stdlib.h>
#define Max1 1000
#define Max2 100


//term data structure------------------------------------------------------------
struct term
{	
	float cf;
	int ex;
};

//polynomial index storage--------------------------------------------------------
struct poly
{
	int beg;
	int end;
};


//================================================================================


//swaps polynomial terms----------------------------------------------------------
void swap(struct term *t, int x, int y)
{
	struct term dummy;
	dummy=t[x];
	t[x]=t[y];
	t[y]=dummy;
	return;
}

//sorts the user input polynomial wrt to exponet----------------------------------
void sort(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	for(int i=p[*freepoly].beg;i<p[*freepoly].end-1;i++)
	{
		int max=i;
		for(int j=i+1;j<p[*freepoly].end;j++)
		{
			if(t[j].ex>t[max].ex)
				max=j;
		}
		swap(t,i,max);
	}
	return;
}
void sortWithId(int id,struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	for(int i=p[id].beg;i<p[id].end-1;i++)
	{
		int max=i;
		for(int j=i+1;j<p[id].end;j++)
		{
			if(t[j].ex>t[max].ex)
				max=j;
		}
		swap(t,i,max);
	}
	return;
}



//reads the polynomial------------------------------------------------------------
void read(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	int n;
	printf("Enter the number of terms: ");
	scanf("%d", &n);
	
	p[*freepoly].beg = *freeterm;
	p[*freepoly].end = (*freeterm) + n;
	
	
	for(int i=0;i<n;i++)
	{
		printf("Enter the exponet of term %d: ", i+1);
		scanf("%d", &t[*freeterm].ex);
		
		//check if exponet already taken-------------
		int flag=0;
		for(int j=*freeterm-1;j>=(*freeterm)-i;j--)
		{
			if(t[j].ex==t[*freeterm].ex)
			{
				i--;
				printf("Exponet already occupied!\n");
				flag=1;
				break;
			}
		}
		if(flag!=1)
		{
			printf("Enter the coefficient of term %d: ", i+1);
			scanf("%f",  &t[*freeterm].cf);
			(*freeterm)++;
		}
	}
	sort(t,p,freeterm,freepoly);
	(*freepoly)=(*freepoly)+1;
	return;
}







//displaying the menu--------------------------------------------------------------------
int menu()
{
	printf("MENU:\n");
	printf("0. Input\n");
	printf("1. Addition\n");
	printf("2. Substraction\n");
	printf("3. Multiplication\n");
	printf("4. Multiplication with a constant\n");
	printf("5. Check if zero\n");
	printf("6. Return degree\n");
	printf("7. Exit\n");
	
	int choice;
	printf("Enter choice : ");
	scanf(" %d",&choice);
	return choice;
}


//input---------------------------------------
void input(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	while(1)
	{
		system("clear");
		printf("Enter the polynomial no. %d----------\n", (*freepoly)+1);
		read(t,p,freeterm,freepoly);
		printf("\n");
		char choice;
		printf("Do you want to input more polynomials (y/n):");
		scanf(" %c",&choice);
		if(choice !='y')
			return;	
	}
	return;
}


//prints a given polynomial-----------------------------------------
void printPoly(struct term *t, struct poly *p, int x)
{
	for(int i=p[x].beg;i<p[x].end;i++)
	{
		printf("%fx^%d ",t[i].cf,t[i].ex);
		if(i!=p[x].end-1)
			printf("+ ");
	}
	return;
}


//prints the all the available polynomials--------------------------
void printAllPoly(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	printf("Available polynomials:\n");
	
	if(*freepoly==0)
	{
		printf("Empty\n");
		printf("----------------------------\n");
		return;
	}
	
	for(int i=0;i<*freepoly;i++)
	{
		printf("%d. ",i+1);
		printPoly(t,p,i);
		//printf(" beg:%d end:%d",p[i].beg,p[i].end);
		printf("\n");
	}
	
	//printf("\nFreeterm: %d\nFreepoly: %d\n",*freeterm,*freepoly);
	printf("----------------------------\n");
	return;
}


//arithmetic operations================================================================


//addition-----------------------------------------------------------------------------
void add(int id1,int id2, struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	int id1beg=p[id1].beg,id1end=p[id1].end;
	int id2beg=p[id2].beg,id2end=p[id2].end;
	
	int i1=id1beg,i2=id2beg;
	
	int n=(t[id1beg].ex>t[id2beg].ex)?(t[id1beg].ex):(t[id2beg].ex);
	p[*freepoly].beg=*freeterm;
	
	//printf("%d %d %d\n",n,t[id1beg].ex,t[id2beg].ex);
	for(int i=n;i>=0;i--)
	{
		struct term dummy;
		dummy.cf=0;
		dummy.ex=i;
		
		if(i1<id1end && t[i1].ex==i)
		{
			dummy.cf+=t[i1].cf;
			i1++;
		}
		if(i2<id2end && t[i2].ex==i)
		{
			dummy.cf+=t[i2].cf;
			i2++;
		}
		
		if(dummy.cf!=0)
		{
			t[*freeterm]=dummy;
			(*freeterm)=(*freeterm)+1;
		}
	}
	
	p[*freepoly].end=*freeterm;
	(*freepoly)=(*freepoly)+1;

	return;
}
void addition(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	system("clear");
	printAllPoly(t,p,freeterm,freepoly);
	
	int id1,id2;
	printf("Enter the ID of the 1st polynomial: ");
	scanf(" %d",&id1);
	printf("Enter the ID of the 2nd polynomial: ");
	scanf(" %d",&id2);
	
	id1-=1;
	id2-=1;
	add(id1,id2,t,p,freeterm,freepoly);
}


//substraction--------------------------------------------------------------------------
void substract(int id1,int id2, struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	int id1beg=p[id1].beg,id1end=p[id1].end;
	int id2beg=p[id2].beg,id2end=p[id2].end;
	
	int i1=id1beg,i2=id2beg;
	
	int n=(t[id1beg].ex>t[id2beg].ex)?(t[id1beg].ex):(t[id2beg].ex);
	p[*freepoly].beg=*freeterm;
	
	printf("%d %d %d\n",n,t[id1beg].ex,t[id2beg].ex);
	for(int i=n;i>=0;i--)
	{
		struct term dummy;
		dummy.cf=0;
		dummy.ex=i;
		
		if(i1<id1end && t[i1].ex==i)
		{
			dummy.cf+=t[i1].cf;
			i1++;
		}
		if(i2<id2end && t[i2].ex==i)
		{
			dummy.cf+=-t[i2].cf;
			i2++;
		}
		
		if(dummy.cf!=0)
		{
			t[*freeterm]=dummy;
			(*freeterm)=(*freeterm)+1;
		}
	}
	
	p[*freepoly].end=*freeterm;
	(*freepoly)=(*freepoly)+1;

	return;
}
void substraction(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	system("clear");
	printAllPoly(t,p,freeterm,freepoly);
	
	int id1,id2;
	printf("Enter the ID of the 1st polynomial: ");
	scanf(" %d",&id1);
	printf("Enter the ID of the 2nd polynomial: ");
	scanf(" %d",&id2);
	
	id1-=1;
	id2-=1;
	substract(id1,id2,t,p,freeterm,freepoly);
	return;
}

//constant_multliplication--------------------------------------------------------------
void const_multiply(int id, float c,struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	p[*freepoly].beg=(*freeterm);
	for(int i=p[id].beg;i<p[id].end;i++)
	{
		struct term dummy;
		dummy.ex=t[i].ex;
		dummy.cf=(t[i].cf)*c;
		t[*freeterm]=dummy;
		(*freeterm)=(*freeterm)+1;
	}
	p[*freepoly].end=(*freeterm);
	(*freepoly)=(*freepoly)+1;
	return;
}
void const_multiplication(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	system("clear");
	printAllPoly(t,p,freeterm,freepoly);

	int id;
	printf("Enter the ID of the polynomial: ");
	scanf("%d",&id);
	id--;
	float c;
	printf("Enter the constant: ");
	scanf("%f",&c);

	const_multiply(id,c,t,p,freeterm,freepoly);
	return;
}

//check_if_zero-------------------------------------------------------------------------
int zero(int id,struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	return (p[id].beg==p[id].end);
}
void check_zero(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	system("clear");
	printAllPoly(t,p,freeterm,freepoly);
	printf("Enter the id of the polynomial:");
	int id;
	scanf("%d",&id);
	id--;
	if(zero(id,t,p,freeterm,freepoly))	
	{
		printf("zero polynomial\n(press any key to continue)");
		getchar();
		getchar();
	}
	else
	{
		printf("non zero polynomial\n(press any key to continue)");
		getchar();
		getchar();
	}
	return;
}


//return_degree--------------------------------------------------------------------------
int degree(int id,struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	return t[p[id].beg].ex;
}
void return_degree(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	system("clear");
	printAllPoly(t,p,freeterm,freepoly);
	printf("Enter the id of the polynomial:");
	int id;
	scanf("%d",&id);
	id--;
	printf("the degree is : %d",degree(id,t,p,freeterm,freepoly));
	getchar();
	getchar();
	return;
}











//multiplication()------------------------------------------------------------------------
void inc_ex(int id, int e,struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	for(int i=p[id].beg;i<p[id].end;i++)
		t[i].ex+=e;
	return;
}
void multiply(int id1,int id2,struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	int flag=0;
	for(int i=p[id1].beg;i<p[id1].end;i++)
	{
		const_multiply(id2,t[i].cf,t,p,freeterm,freepoly);
		inc_ex((*freepoly)-1,t[i].ex,t,p,freeterm,freepoly);
		if(flag)
		{
			add((*freepoly)-2,(*freepoly)-1,t,p,freeterm,freepoly);
			sortWithId((*freepoly)-1,t,p,freeterm,freepoly);
			//printf("%d %d\n",(*freeterm)-1,(*freeterm)-2);
			//getchar();
			//getchar();
		}
		flag=1;
	}
	return;
}
void multiplication(struct term *t, struct poly *p, int *freeterm, int *freepoly)
{
	system("clear");
	printAllPoly(t,p,freeterm,freepoly);
	
	int id1,id2;
	printf("Enter the id of the first polynomial: ");
	scanf("%d",&id1);
	id1--;
	printf("Enter the id of the second polynomial: ");
	scanf("%d",&id2);
	id2--;


	multiply(id1,id2,t,p,freeterm,freepoly);
	return;
}




































//======================================================================================
int main()
{
	system("clear");
	struct term t[Max1];
	struct poly p[Max2];
	int freeterm =0, freepoly=0;
	

	while(1)
	{
		system("clear");
		//printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printAllPoly(t,p,&freeterm,&freepoly);
		int choice = menu();
	
		switch(choice)
		{
			case 0: input(t,p,&freeterm,&freepoly);break;
			case 1: addition(t,p,&freeterm,&freepoly);break;
			case 2: substraction(t,p,&freeterm,&freepoly);break;
			case 3: multiplication(t,p,&freeterm,&freepoly);break;
			case 4: const_multiplication(t,p,&freeterm,&freepoly);break;
			case 5: check_zero(t,p,&freeterm,&freepoly);break;
			case 6: return_degree(t,p,&freeterm,&freepoly);break;
			case 7: return 0;
		}
	}
	return 0;
}


















