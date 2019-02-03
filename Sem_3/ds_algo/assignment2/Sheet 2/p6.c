#include <stdio.h>
#define size 500

//--------------------------------------------------------------------------------------------
void fill_arr(int arr[size],int n){
	int num;
	for(int i=0;i<n;++i){
		scanf("%d",&num);
		arr[i]=num;
	};
};
void display(int arr[size],int n){
	for(int i=0;i<n;++i){
		printf("%d ",arr[i]);
	};printf("\n");
};
//--------------------------------------------------------------------------------------------
int equal(int arr[size],int n){
	for(int i=0;i<n-1;++i){
		if(arr[i]!=arr[i+1]){return 0;}
	};
	return 1;
};

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
int find_sort_order(int arr[size],int n){
	if(equal(arr,n)==1){return 1;}
	else if(ascend(arr,n)==1){return 2;}
	else if(descend(arr,n)==1){return 3;}
	else{return 0;};
}
//----------------------------------------------------------------------------------------------
int comp_ord(int s1,int s2,int x,int y){
	if(s1==s2){
		switch(s1){
			case 0: return 0;
				break;
			case 1: if(x==y){return 1;}return 0;
				break;
			case 2: return 2;
				break;
			case 3: return 3;
				break;
		};
	}
	else{
		if(s1==1 && s2==2){return 4;}
		else if(s1==1 && s2==3){return 5;}
		else if(s1==2 && s2==1){return 6;}
		else if(s1==3 && s2==1){return 7;}
		else{return 0;};
	};
};		
//--------------------------------------------------------------------------------------------
void equal_ascend(int arr1[size],int n1,int arr2[size],int n2,int arr3[size]){
	int i;int c=0;
	for(i=0;i<n2;++i){
		if(arr1[0]<=arr2[i]){
			for(int j=0;j<n1;++j){arr3[c]=arr1[0];c++;};
			break;
		}
		else{arr3[c]=arr2[i];c++;};
	};
	if(i<=n2-1){
		for(;i<n2;++i){arr3[c]=arr2[i];c++;};
	};
};
void equal_descend(int arr1[size],int n1,int arr2[size],int n2,int arr3[size]){
	int i;int c=0;
	for(i=0;i<n2;++i){
		if(arr1[0]>=arr2[i]){
			for(int j=0;j<n1;++j){arr3[c]=arr1[0];c++;};
			break;
		}
		else{arr3[c]=arr2[i];c++;};
	};
	if(i<=n2-1){
		for(;i<n2;++i){arr3[c]=arr2[i];c++;};
	};
};

void ascend_both(int arr1[size],int n1,int arr2[size],int n2,int arr3[size]){
	int arr[2*size];int c=0;
	for(int i=0;i<n1;++i){arr[c]=arr1[i];c++;};
	for(int i=0;i<n2;++i){arr[c]=arr2[i];c++;};
	
	c=0;
	int index1=0;
	int index2=n1;
	
	while(index1<n1 && index2<n1+n2){
		while(arr[index1]<=arr[index2] && index1<n1 && index2<n1+n2){
			arr3[c]=arr[index1];c++;index1++;
		};
		while(arr[index2]<=arr[index1] && index1<n1 && index2<n1+n2){
			arr3[c]=arr[index2];c++;index2++;
		};
	};
	
	if(index1==n1){
		for(int i=index2;i<n2+n1;++i){arr3[c]=arr[i];c++;};
	};
	if(index2==n2+n1){
		for(int i=index1;i<n1;++i){arr3[c]=arr[i];c++;};
	};
	
};

void descend_both(int arr1[size],int n1,int arr2[size],int n2,int arr3[size]){
	int arr[2*size];int c=0;
	for(int i=0;i<n1;++i){arr[c]=arr1[i];c++;};
	for(int i=0;i<n2;++i){arr[c]=arr2[i];c++;};

	c=0;
	int index1=0;
	int index2=n1;
	
	while(index1<n1 && index2<n1+n2){
		while(arr[index1]>=arr[index2] && index1<n1 && index2<n1+n2){
			arr3[c]=arr[index1];c++;index1++;
		};
		while(arr[index2]>=arr[index1] && index1<n1 && index2<n1+n2){
			arr3[c]=arr[index2];c++;index2++;
		};
	};
	
	if(index1==n1){
		for(int i=index2;i<n2+n1;++i){arr3[c]=arr[i];c++;};
	};
	if(index2==n2+n1){
		for(int i=index1;i<n1;++i){arr3[c]=arr[i];c++;};
	};
};
			
//--------------------------------------------------------------------------------------------
void merge(int arr1[size],int n1,int arr2[size],int n2,int s,int arr3[size]){
	switch(s){
		case 1: ascend_both(arr1,n1,arr2,n2,arr3);break;
		case 2: ascend_both(arr1,n1,arr2,n2,arr3);break;
		case 3: descend_both(arr1,n1,arr2,n2,arr3);break;
		case 4: equal_ascend(arr1,n1,arr2,n2,arr3);break;
		case 5: equal_descend(arr1,n1,arr2,n2,arr3);break;
		case 6: equal_ascend(arr2,n2,arr1,n1,arr3);break;
		case 7: equal_descend(arr2,n2,arr1,n1,arr3);break;
	};
};
//--------------------------------------------------------------------------------------------
int main(){
	int n1,n2,s1,s2;
	int arr1[size],arr2[size],arr3[size];

	printf("ENTER SIZE OF ARRAY 1 :");
	scanf("%d",&n1);
	printf("ENTER ARRAY\n");
	fill_arr(arr1,n1);
	
	printf("ENTER SIZE OF ARRAY 2 :");
	scanf("%d",&n2);
	printf("ENTER ARRAY\n");
	fill_arr(arr2,n2);

	s1=find_sort_order(arr1,n1);
	s2=find_sort_order(arr2,n2);

	if(comp_ord(s1,s2,arr1[0],arr2[0])==0){printf("ARRAYS CANNOT BE MERGES\n");}
	else{merge(arr1,n1,arr2,n2,comp_ord(s1,s2,arr1[0],arr2[0]),arr3);display(arr3,n1+n2);};
	

	return 0;
};

