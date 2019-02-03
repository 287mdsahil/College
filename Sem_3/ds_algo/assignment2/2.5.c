#include<stdio.h>
#define max 50
int checkSort(int *a,int n){
	if(n==1 || n==0)
		return 0;
		
	int flag=0;
	if(a[0]<a[1]) flag=1;
	else if(a[0]>a[1]) flag=-1;
	
	for(int i=1;i<n;i++)
	{
		
	}
	
	return flag;
}
int main(){
	int a[max],n;
	printf("Enter the size of the array: ");
	scanf(" %d",&n);
	printf("Enter the array : ");
	for(int i=0;i<n;i++){
		scanf(" %d",&a[i]);		
	}

	int order=checkSort(a,n);
	return 0;
}
