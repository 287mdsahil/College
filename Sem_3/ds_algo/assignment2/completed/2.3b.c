#include<stdio.h>
#include<stdlib.h>
#define Max 100


void displayList(int*);
int menu(int*);
void input(int*);
int empty(int*);
void checkEmpty(int*);
int len(int*);
void checkLen(int*);
int read(int,int*);
void readElement(int*);
void write(int,int,int*);
void writeElement(int*);
void insert(int,int,int*);
void insertElement(int*);
void delete(int,int*);
void deleteElement(int*);
int search(int,int*);
void searchKey(int*);
void sortA(int*);
void sortD(int*);
void sortList(int*);

//--------------------------------------------------------
int main()
{
	int list[Max];
	list[0]='#';
	int choice;
	while(1){
		choice=menu(list);
		switch(choice){
			case 0: input(list);break;
			case 1: checkEmpty(list);break;
			case 2: checkLen(list);break;
			case 3: readElement(list);break;
			case 4: writeElement(list);break;
			case 5: insertElement(list);break;
			case 6: deleteElement(list);break;
			case 7: searchKey(list);break;
			case 8: sortList(list);break;
			case 9: return 0;
		}
	}
	return 0;    
    return 0;
}


//display
void displayList(int *list){
	printf("\n:- ");
	for(int i=0;list[i]!='#';i++)
		printf("%d ",list[i]);
	printf("\n\n");
}
int menu(int *list){
	system("clear");
	displayList(list);
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
void input(int *list){
	printf("Enter the list: ");
    int c;
	int i=0;
	while(scanf(" %d",&c)){
		list[i]=c;
		i++;
	}
	list[i]='#';
	getchar();
	return;
}



//emptycheck
int empty(int *list){
	return list[0]=='#';
}
void checkEmpty(int *list){
	if(empty(list)){
		printf("The list is empty!");
		getchar();
		getchar();
	}
	else{
		printf("The list is not empty!");
		getchar();
		getchar();
	}
}


//checkLen
int len(int *list){
	int i=0;
	for(i;list[i]!='#';i++);
	return i;
}
void checkLen(int *list){
	printf("The length of the list is: %d\n",len(list));
	getchar();
	getchar();
	return;
}



//readelement
int read(int i,int *list){
	return list[i];
}
void readElement(int *list){
	printf("Enter the index of the element to read: ");
	int i;
	scanf(" %d",&i);
	if(i<0 || i>len(list)){
		printf("Invalid Index!\n");
	}
	else
		printf("The element at index %d is : %d\n",i,read(i,list));
	getchar();
	getchar();
	return;
}


//writeelement
void write(int i,int c,int *list){
	list[i]=c;
}
void writeElement(int *list){
	int i,c;
	printf("Enter the index of the element to overwrite: ");
	scanf(" %d",&i);
	if(i<0 || i>len(list)){
		printf("Invalid Index!\n");
		return;
	}
	printf("Enter the new value: ");
	scanf(" %d",&c);
	write(i,c,list);
	return;
}


//insert
void insert(int i,int c,int *list){
	int n=len(list);
	if(n==Max-1){
		printf("Overflow!!");
		getchar();
		getchar();
		return;
	}
	n++;
	for(int j=n;j>i;j--)
		list[j]=list[j-1];
	list[i]=c;
	return;
}
void insertElement(int *list){
	int i,c;
	printf("Enter the index to insert :");
	scanf(" %d",&i);
	if(i<0 || i>len(list)){
		printf("Invalid Index!!!");
		getchar();
		getchar();
		return;
	}
	printf("Enter the value :");
	scanf(" %d",&c);
	insert(i,c,list);
	return;
}


//delete
void delete(int i,int *list){
	for(int j=i;list[j]!='#';j++)
		list[j]=list[j+1];
	return;
}
void deleteElement(int *list){
	int i;
	if(empty(list)){
		printf("Underflow!!");
		getchar();
		getchar();
		return;
	}
	printf("Enter the index of the element to delete :");
	scanf(" %d",&i);
	if(i<0 || i>=len(list)){
		printf("Invalid Index!!!");
		getchar();
		getchar();
		return;
	}
	delete(i,list);
	return;
}





//search
int search(int k,int *list){
	for(int i=0;list[i]!='#';i++){
		if(list[i]==k)
			return i;
	}
	return -1;
}
void searchKey(int *list){
	printf("Enter the key to search for :");
	int k;
	scanf(" %d",&k);
	int i=search(k,list);
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
void sortD(int *list){
	for(int i=0;list[i+1]!='#';i++){
		int max=i;
		for(int j=i+1;list[j]!='#';j++)
			if(list[max]<list[j]){
				max=j;
			}
		int dummy=list[max];
		list[max]=list[i];
		list[i]=dummy;
	}
	return;
}
void sortA(int *list){
	for(int i=0;list[i+1]!='#';i++){
		int min=i;
		for(int j=i+1;list[j]!='#';j++)
			if(list[min]>list[j]){
				min=j;
			}
		int dummy=list[min];
		list[min]=list[i];
		list[i]=dummy;
	}
	return;
}
void sortList(int *list){
	int n=len(list);
	printf("Enter 1 for assceding, 0 for decending :");
	int x;
	scanf(" %d",&x);

	if(x==1)	sortA(list);
	else if(x==0)	sortD(list);
	else {
		printf("Invalid input");
		getchar();
		getchar();
	}
	return;
}