#include <stdio.h>
#define size 500

int index1=0;              //KEEPS CPUNT OF NUMBER OF LISTS IN LIST POOL

int list_pool[size][size];
void display(int l);
//--------------------FUNCTIONS---------------------------------------------------------------

//CHECKS IF LIST IS EMPTY
int empty(int l){                      //RETURNS TRUE IF EMPTY
	int x=list_pool[l-1][0];
	if(x==-1){return 1;}
	return 0;
};

//RETURNS LENGTH OF THE LIST
int length(int l){
	int len=0;
	while(1){
		if(list_pool[l-1][len]==-1){return len;}
		else{len++;};
	};
};

//READS ELEMENT AT POSITION POS
int read(int l,int pos){
	return list_pool[l-1][pos];
};

//WRITES ELEMENT AT POSITION POS
void write(int l,int pos,int obj){
	if(length(l)<pos){printf("INVALID OPERATION. INDEX DOESNOT EXIST.\n");}
	else{
		list_pool[l-1][pos]=obj;
		printf("ELEMENT AT %d CHANGED\n",pos);
		display(l);};
};

//INSERT ELEMENT OBJ AT POSITION POS
void insert(int l,int pos,int obj){
	if(length(l)<pos){printf("INVALID OPERATION. INDEX DOESNOT EXIST.\n");}
	else{
		for(int i=length(l);i>=pos;--i){
			list_pool[l-1][i+1]=list_pool[l-1][i];
		};
		list_pool[l-1][pos]=obj;
		printf("INSERTION SUCCESSFUL\n");display(l);
	};
};

//DELETE ELEMENT AT POSITION POS
void delete(int l,int pos){
	if(length(l)<pos){printf("INVALID OPERATION. INDEX DOESNOT EXIST.\n");}
	else{
		for(int i=pos;i<length(l)+1;++i){
			list_pool[l-1][i]=list_pool[l-1][i+1];
		};
		printf("DELETION SUCCESSFUL\n");display(l);
	};
};

//SEARCHES FOR AN ELEMENT OBJ
void search(int l,int obj){
	if(empty(l)){printf("INVALID OPERATION. LIST EMPTY\n");}
	else{
		for(int i=0;i<length(l);++i){
			if(list_pool[l-1][i]==obj){printf("%d FOUND AT %d\n",obj,i);return;}
		};
		printf("NOT FOUND\n");
	};
};

//SORTS IN ASCENDING ORDER
void ascend(int l){
	int m=length(l);
	int t,k;
	for(int i=1;i<m;++i){
		t=list_pool[l-1][i];
		k=i-1;
		while(t<list_pool[l-1][k] && k>=0){list_pool[l-1][k+1]=list_pool[l-1][k];k=k-1;};
		list_pool[l-1][k+1]=t;
	};
};

//REVERSES A LIST
void reverse(int l){
	int li1[size];
	for(int i=length(l)-1;i>=0;--i){
		li1[length(l)-1-i]=list_pool[l-1][i];
	};
	li1[length(l)]=-1;
	for(int i=0;i<length(l)+1;++i){
		list_pool[l-1][i]=li1[i];
	};
};

//SORTS A LIST ACCORDING TO GIVEN ORDER
void sort(int l,int ord){
	if(empty(l)){printf("INVALID OPERATION. LIST EMPTY\n");}
	else{
		if(ord==1){ascend(l);}
		else{ascend(l);reverse(l);};
		printf("LIST SORTED SUCCESSFULLY\n");display(l);
	};
}
//-------------------------LIST BASICS (INITIALIZE,DISPLAY ALL AVAILABLE LISTS)-------------------------------------------
void init_list(){
	int len=0;
	int num;
	int choice;
	while(1){
		printf("PRESS 0 TO EXIT OR 1 TO ADD ELEMENTS TO LIST :");
		scanf("%d",&choice);
		if(choice==0){break;}
		else{
			printf("ENTER ELEMENT TO ADD TO LIST :");
			scanf("%d",&num);
			list_pool[index1][len]=num;
			len++;
		
		};
	};
	list_pool[index1][len]=-1;
	index1++;
}

void display_all(){
	printf("ALL AVAILABLE LISTS :\n");
	for(int i=0;i<index1;++i){
		printf("%d. ",i+1);
		display(i+1);
	};
};

void display(int l){
	printf("[");
	for(int j=0;j<length(l);++j){
		printf("%d,",list_pool[l-1][j]);
	};
	printf("]\n");
};

//-------------------------MENU OF FUNCTIONS--------------------------------------------
void menu(){
	display_all();

	int choice;
	printf("\nCHOOSE AN OPTION BY PRESSING:\n1. CHECK WETHER EMPTY\n2. FIND LENGTH\n3. READ ELEMENT AT GIVEN POSITION\n4. WRITE ELEMENT AT GIVEN POSITION\n");
	printf("5. INSERT ELEMENT AT GIVEN POSITION\n6. DELETE ELEMENT AT GIVEN POSITION\n7. SEARCH FOR AN ELEMENT\n8. SORT A LIST\n");
	scanf("%d",&choice);
	
	int l,pos,obj,ord;
	printf("ENTER LIST NUMBER :");
	scanf("%d",&l);
	if(choice>=3 && choice<=6){printf("ENTER POSITION :");scanf("%d",&pos);};
	if(choice==5 || choice==7 || choice==4){printf("ENTER ELEMENT :");scanf("%d",&obj);};
	if(choice==8){printf("PRESS:\n1 FOR ASCENDING ORDER\n0 FOR DESCENDING ORDER\n");scanf("%d",&ord);};
	

	switch(choice){
		case 1: if(empty(l)){printf("LIST IS EMPTY\n");}
			else{printf("LIST IS NOT EMPTY\n");};
			break;
		case 2: printf("LENGTH :%d\n",length(l));
			break;
		case 3: if(empty(l)){printf("LIST IS EMPTY. INVALID OPERATION.\n");break;}
			printf("ELEMENT AT %d: %d\n",pos,read(l,pos));
			break;
		case 4: write(l,pos,obj);
			break;
		case 5: insert(l,pos,obj);
			break;
		case 6: delete(l,pos);
			break;
		case 7: search(l,obj);
			break;
		case 8: sort(l,ord);
			break;
	};
};		

//--------------------------MAIN FUNCTION-----------------------------------------------------
int main(){
	while(1){
		int choice;
		printf("\nPRESS 0 TO EXIT\nPRESS 1 TO DISPLAY FUNCTION MENU\nPRESS 2 TO INITIALIZE A LIST\n");
		scanf("%d",&choice);
		
		if(choice==0){break;}
		else if(choice==1){menu();}
		else{init_list();};
	};
	return 0;
}
