#include <stdio.h>
#define size 500

void fill_arr(int arr[size],int n){
	int num;
	for(int i=0;i<n;++i){
		scanf("%d",&num);
		arr[i]=num;
	};
};

//--------------------------------------------------------------------------------------------

int equal(int arr[size],int n){
	for(int i=0;i<n-1;++i){
		if(arr[i]!=arr[i+1]){return 0;}
	};
	return 1;
}

int ascend(int arr[size],int n){
	for(int i=0;i<n-1;++i){
		if(arr[i]>=arr[i+1]){return 0;}
	};
	return 1;
}

int descend(int arr[size],int n){
	for(int i=0;i<n-1;++i){
		if(arr[i]<=arr[i+1]){return 0;}
	};
	return 1;
}

//---------------------------------------------------------------------------------------------

void find_sort_order(int arr[size],int n){
	if(equal(arr,n)==1){printf("ARRAY HAS ALL EQUAL ELEMENTS\n");return;}
	else if(ascend(arr,n)==1){printf("ARRAY IS IN ASCENDING ORDER\n");return;}
	else if(descend(arr,n)==1){printf("ARRAY IS IN DESCENDING ORDER\n");return;}
	else{printf("ARRAY IS NOT SORTED\n");return;};
}

//----------------------------------------------------------------------------------------------

int main(){
	int n;
	int arr[size];
	printf("ENTER SIZE OF ARRAY :");
	scanf("%d",&n);
	printf("ENTER ARRAY\n");
	fill_arr(arr,n);
	find_sort_order(arr,n);
	return 0;
}	
