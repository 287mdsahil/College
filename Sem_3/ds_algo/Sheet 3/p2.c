#include <stdio.h>
#include <stdlib.h>
#define clrscr() printf("\033[H\033[J")

//---------------------------------------------------------------------
//DEFINIG A NODE
struct node{
	int val;
	struct node* next;
};
typedef struct node node;

//----------- ---------BASIC FUNCTIONS--------------------------------------
void  display(node*);
//INITIALIZE A LINKED LIST
node* init_l(node** head){
	(*head)->next=NULL;
	(*head)->val=0;
};

//CREATE A NODE
void create_node(node* n,int num){
	n->val=num;
	n->next=NULL;
};

//DISPLAY A LIST POINTED TO BY HEAD
void display(node* head){
	node* cur;
	cur=(node*)malloc(sizeof(node));
	cur=head;
	printf("[ ");
	while(1){
		if(cur->next==NULL){break;};
		printf("%d,",cur->val);
		cur=cur->next;
	};
	printf("]\n");
};

//-------------------------------------------------------------------
//CHECKS WETHER LIST IS EMPTY-RETURNS TRUE IF EMPTY
int empty_l(node* head){
	if(head->next==NULL){return 1;}
	return 0;
};

//CHECKS IF LAST NODE OF LIST REACHED-RETURNS TRUE IF REACHED
int atend_l(node* n){
	if(n->next==NULL){return 1;}
	return 0;
};

//INSERT A NODE TO THE HEAD OF LIST
void insert_front(node* target,node** head){
	target->next=*head;	
	*head=target;
	//free((void*)target);
};

//INSERT A NODE AFTER THE NODE POINTED TO BY PREV
void insert_after(node* n,node* prev){
	n->next=prev->next;
	prev->next=n;
};

//DELETE FIRST ELEMENT OF LIST
void delete_front(node** head){
	if(empty_l(*head)){printf("INVALID OPERATION.LIST IS EMPTY.\n");return;}
	*head=(*head)->next;
};

//DELETE A NODE AFTER THE NODE POINTED TO BY PREV
void delete_after(node* prev){
	if(atend_l(prev)){printf("INVALID OPERATION.THIS IS THE LAST NODE.\n");return;}
	node* n;
	n=prev->next;
	prev->next=n->next;
};

//-------------------------------------------------------------------------------------------------------
//MAIN FUNCTION
int main(){
	FILE* fp;
	int num,t;
	fp=fopen("p2.txt","r");
	
	node* head1;
	node* head2;
	head1=(node*)malloc(sizeof(node));
	head2=(node*)malloc(sizeof(node));
	init_l(&head1);
	init_l(&head2);

	t=9;
	node* n2;
	n2=(node*)malloc(sizeof(node));
	fscanf(fp,"%d\n",&num);
	node* n1;
	n1=(node*)malloc(sizeof(node));
	create_node(n1,num);
	insert_front(n1,&head2);
	n2=n1;
	//while(fscanf(fp,"%d\n",&num)!=EOF){
	while(t--){
		fscanf(fp,"%d\n",&num);
		node* n1;
		n1=(node*)malloc(sizeof(node));
		create_node(n1,num);
		insert_after(n1,n2);
		n2=n1;
	};
	printf("Printing numbers in natural order\n");
	display(head2);
	fclose(fp);

	fp=fopen("p2.txt","r");
	t=10;
	//while(fscanf(fp,"%d\n",&num)!=EOF){
	while(t--){
		fscanf(fp,"%d\n",&num);
		node* n1;
		n1=(node*)malloc(sizeof(node));
		create_node(n1,num);
		insert_front(n1,&head1);
	};
	printf("----------------------------------------------------------\n");
	printf("Printing numbers in reverse order\n");
	display(head1);
	fp=fopen("p2.txt","r");

	return 0;
};

























