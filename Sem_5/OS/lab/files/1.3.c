#include<stdio.h>
#include<string.h>
#define Max 100
#define maxsize 200



//Float=========================================================================================
//=====================! precission error !=====================================================
void swap_float(float *a,float *b)
{
	float dummy=*a;
	*a=*b;
	*b=dummy;
}
void selection_sort_float(float a[], int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		if(a[min]<a[i])
			swap_float(&a[min],&a[i]);
	}
}
//-------------------------------------------------------------------------------------------------
float linear_float(float *a,int n,float x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
			return i;
	}
	return -1;
}
//--------------------------------------------------------------------------------------------------
float binary_float(float *a,int l,int h,float x)
{
	int mid=(l+h)/2;
	if(a[mid]==x)
		return mid;
	else if(l==h)
		return -1;
	else if(a[mid]>x)
		return binary_float(a,l,h-1,x);
	else if(a[mid]<x)
		return binary_float(a,l+1,h,x);
}
//--------------------------------------------------------------------------------------------------
void floats()
{

	int n;
	printf("Insert length: ");
	scanf("%d",&n);
	
	float a[n];
	printf("Enter the array:\n");
	for(int i=0;i<n;i++)
		scanf("%f",&a[i]);
	
	
	float x;
	printf("Enter the number to search:");
	scanf("%f",&x);
	
	//searching using linear search
	int index=linear_float(a,n,x);
	if(index==-1)
		printf("Not found\n");
	else
		printf("Number found (linear search) index:%d\n",index);
	
	
	//searching using binary search
	selection_sort_float(a,n);
	printf("Array after sorting: ");
	for(int i=0;i<n;i++)
		printf("%f ",a[i]);
	printf("\n");
	index=binary_float(a,0,n,x);	
	if(index==-1)
		printf("Not found\n");
	else
		printf("Number found (linear search) index:%d\n",index);
}

//==========================================================================================











//INTEGERS=========================================================================================
void swap(int *a,int *b)
{
	int dummy=*a;
	*a=*b;
	*b=dummy;
}
void selection_sort(int a[], int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		if(a[min]<a[i])
			swap(&a[min],&a[i]);
	}
}
//-------------------------------------------------------------------------------------------------
int linear_int(int *a,int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
			return i;
	}
	return -1;
}
//--------------------------------------------------------------------------------------------------
int binary_int(int *a,int l,int h,int x)
{
	int mid=(l+h)/2;
	if(a[mid]==x)
		return mid;
	else if(l==h)
		return -1;
	else if(a[mid]>x)
		return binary_int(a,l,h-1,x);
	else if(a[mid]<x)
		return binary_int(a,l+1,h,x);
}
//--------------------------------------------------------------------------------------------------
void integers()
{

	int n;
	printf("Insert length: ");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter the array:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	
	int x;
	printf("Enter the number to search:");
	scanf("%d",&x);
	
	//searching using linear search
	int index=linear_int(a,n,x);
	if(index==-1)
		printf("Not found\n");
	else
		printf("Number found (linear search) index:%d\n",index);
	
	
	//searching using binary search
	selection_sort(a,n);
	printf("Array after sorting: ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	index=binary_int(a,0,n,x);	
	if(index==-1)
		printf("Not found\n");
	else
		printf("Number found (linear search) index:%d\n",index);
}

//============================================================================================










//----------------------------------Words--------------------------------------------------
//BASIC SORTING 
void wordSort(int m,char a[maxsize][maxsize]){
	char temp[maxsize];
	for(int i=0;i<m;++i)
	{
		for(int j=i+1;j<m;++j)
		{
			if(strcmp(a[j],a[i])<0)
			{
				strcpy(temp,a[j]);
				strcpy(a[j],a[i]);
				strcpy(a[i],temp);
			}
		}
	}				
}

//WORD LINEAR SEARCH
void wordlnSearch(int n,char a[maxsize][maxsize],char* obj){
	for(int i=0;i<n;i++){
		if(strcmp(obj,a[i])==0)
		{
			printf("%s found at index (Linear Search) : %d \n",obj,i);
			return;
		}
	}
	printf("%s not in array\n",obj);return;
}

//WORD BINARY SEARCH
void wordbnSearch(int n,char a[maxsize][maxsize] ,char* obj){
	int s,f,mid;
	s=0;
	f=n-1;
	while(s<=f)
	{
		mid=(s+f)/2;
		
		if(strcmp(obj,a[mid])<0)
			f=mid-1;
		else if(strcmp(obj,a[mid])>0)
			s=mid+1;
		else if(strcmp(obj,a[mid])==0)
		{
			printf("%s found at (Binary Search) : %d\n",obj,mid);
			return;
		}
	}
	printf("%s not in array\n",obj);
	return;
}


//WORD ARRAY FILLING
void wordfill(char wordarray[maxsize][maxsize],int n){
	int i=0;
	printf("Enter words to fill word array.\n");
	while(n--){
		scanf("%s",wordarray[i]);
		i=i+1;
	};
};

//DISPLAYING A ARRAY
void display(int n,char a[maxsize][maxsize]){
	for(int i=0;i<n;++i){
		printf("%s ",a[i]);
	};
	printf("\n");
};

//WORD PROCESSING FUNCTION
void wordprocess(){
	char wordarray[maxsize][maxsize];
	char word[maxsize];
	int n;
	
	printf("Enter number of words : ");
	scanf("%d",&n);
	wordfill(wordarray,n);

	printf("Enter word to search : ");
	scanf("%s",word);
	
	wordlnSearch(n,wordarray,word);
	//display(n,wordarray);
	wordSort(n,wordarray);
	
	printf("wordlist after sorting : ");
	display(n,wordarray);
	wordbnSearch(n,wordarray,word);
};	





//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


int main()
{
	int choice;
	printf("Menu:\n1.int\n2.floating numbers\n3.words\nEnter choice:");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:integers();break;
		case 2:floats();break;
		case 3:wordprocess();break;
		default :printf("Incorrect Input\n");break;
	}
	
	return 0;
}
