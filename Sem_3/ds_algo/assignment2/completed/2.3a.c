#include<stdio.h>
#include<stdlib.h>
#define Max 100

int menu(int*,int*);
void displayList(int*,int*);
void checkEmpty(int*,int*);
int empty(int*,int*);
void input(int*,int*);
int len(int*, int*);
void checkLen(int*,int*);
int read(int,int*,int*);
void readElement(int*,int*);
void write(int,int,int*,int*);
void writeElement(int*,int*);
void insert(int,int,int*,int*);
void insertElement(int*,int*);
void delete(int,int*,int*);
void deleteElement(int*,int*);
int search(int,int*,int*);
void searchKey(int*,int*);
void sortList(int*,int*);
void sortA(int*,int*);
void sortD(int*,int*);

//--------------------------------------------------------------------------
int main(){
	int list[Max];
	int n;

	int choice;
	while(1){
		choice=menu(list,&n);
		switch(choice){
			case 0: input(list,&n);break;
			case 1: checkEmpty(list,&n);break;
			case 2: checkLen(list,&n);break;
			case 3: readElement(list,&n);break;
			case 4: writeElement(list,&n);break;
			case 5: insertElement(list,&n);break;
			case 6: deleteElement(list,&n);break;
			case 7: searchKey(list,&n);break;
			case 8: sortList(list,&n);break;
			case 9: return 0;
		}
	}
	return 0;
}
//--------------------------------------------------------------------------




//display
void displayList(int *list, int *n){
	printf("\n:- ");
	for(int i=0;i<*n;i++)
		printf("%d ",list[i]);
	printf("\n\n");
}
int menu(int *list,int *n){
	system("clear");
	displayList(list,n);
	printf("0. Input\n");
	printf("1. Check if empty\n");
	printf("2. Find length\n");
	printf("3. Read nth element\n");
	printf("4. Overwrite nth element\n");
	printf("5. Insert at nth position\n");
	printf("6. Delete from nth position\n");
	printf("7. Search for a key\n");
	printf("8. Sort\n");
	printf("9. Exit\n");
	printf("Enter choice: ");
	int choice;
	scanf(" %d",&choice);
	return choice;
}






//input
void input(int *list, int *n){
	printf("Enter the size(max size 100): ");
	scanf(" %d",n);
	printf("Enter the list: ");
	for(int i=0;i<*n;i++)
		scanf(" %d",&list[i]);
	return;
}






//empty
int empty(int *list, int *n){
	return (*n==0);
}
void checkEmpty(int *list, int *n){
	if(empty(list,n)) printf("Empty");
	else printf("Not empty");
	getchar();
	getchar();
	return;
}






//length
int len(int *list,int *n){
	return *n;
}
void checkLen(int *list,int *n){
	printf("The length is: %d",len(list,n));
	getchar();
	getchar();
	return;
}






//read
int read(int i, int *list, int *n){
	return list[i];
}
void readElement(int *list,int *n){
	int i;
	printf("Enter the index of the element: ");
	scanf(" %d",&i);
	if(i<0 || i>=*n){
		printf("Invalid Index!!!");
		getchar();
		getchar();
		return;
	}
	printf("The value at index %d is :%d",i,read(i,list,n));
	getchar();
	getchar();
	return;
}




//write
void write(int i,int c,int *list,int *n){
	list[i]=c;
	return;
}
void writeElement(int *list,int *n){
	printf("Enter the element index :");
	int i;
	scanf(" %d",&i);
	if(i<0 || i>=*n){
		printf("Invalid Index!!!");
		getchar();
		getchar();
		return;
	}
	printf("Enter the new value :");
	int c;
	scanf(" %d",&c);
	write(i,c,list,n);
	return;
}





//insert
void insert(int i,int c,int *list, int *n){
	if(*n==Max-1){
		printf("Overflow!!");
		getchar();
		getchar();
		return;
	}
	(*n)=(*n)+1;
	for(int j=*n;j>i;j--)
		list[j]=list[j-1];
	list[i]=c;
	return;
}
void insertElement(int *list,int *n){
	int i,c;
	printf("Enter the index to insert :");
	scanf(" %d",&i);
	if(i<0 || i>*n){
		printf("Invalid Index!!!");
		getchar();
		getchar();
		return;
	}
	printf("Enter the value :");
	scanf(" %d",&c);
	insert(i,c,list,n);
	return;
}




//delete
void delete(int i,int *list,int *n){
	(*n)=(*n)-1;
	for(int j=i;j<*n;j++)
		list[j]=list[j+1];
	return;
}
void deleteElement(int *list,int *n){
	int i;
	if(empty(list,n)){
		printf("Underflow!!");
		getchar();
		getchar();
		return;
	}
	printf("Enter the index of the element to delete :");
	scanf(" %d",&i);
	if(i<0 || i>=*n){
		printf("Invalid Index!!!");
		getchar();
		getchar();
		return;
	}
	delete(i,list,n);
	return;
}

//search
int search(int k,int *list, int *n){
	for(int i=0;i<*n;i++){
		if(list[i]==k)
			return i;
	}
	return -1;
}
void searchKey(int *list,int *n){
	printf("Enter the key to search for :");
	int k;
	scanf(" %d",&k);
	int i=search(k,list,n);
	if(i==-1){
		printf("Key not found!");
		getchar();
		getchar();
		return;
	}
	else{
		printf("Key found (first occurance) at index :%d",i);
		getchar();
		getchar();
		return;
	}
}



//sort
void sortD(int *list,int *n){
	for(int i=0;i<(*n)-1;i++){
		int max=i;
		for(int j=i+1;j<(*n);j++)
			if(list[max]<list[j]){
				max=j;
			}
		int dummy=list[max];
		list[max]=list[i];
		list[i]=dummy;
	}
	return;
}
void sortA(int *list,int *n){
	for(int i=0;i<(*n)-1;i++){
		int min=i;
		for(int j=i+1;j<(*n);j++)
			if(list[min]>list[j]){
				min=j;
			}
		int dummy=list[min];
		list[min]=list[i];
		list[i]=dummy;
	}
	return;
}
void sortList(int *list,int *n){
	printf("Enter 1 for assceding, 0 for decending :");
	int x;
	scanf(" %d",&x);

	if(x==1)	sortA(list,n);
	else if(x==0)	sortD(list,n);
	else {
		printf("Invalid input");
		getchar();
		getchar();
	}
	return;
}


