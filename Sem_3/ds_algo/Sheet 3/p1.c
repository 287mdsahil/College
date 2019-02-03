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

//CREATE A LIST
void create_list(node** head){
	int choice,num;
	while(1){
		node* n;
		n=(node*)malloc(sizeof(node));
		printf("Enter 1 to continue 0 to exit :");
		scanf("%d",&choice);
		if(choice==0){break;};
		printf("Enter value to store in node :");
		scanf("%d",&num);
		create_node(n,num);
		n->next=(*head);
		*head=n;
	};
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
	int choice;
		
	printf("Select option number to carry out the operation:\n");
	printf("1.Check wether linked list is empty.\n");
	printf("2.Check if last node has been reached.\n");
	printf("3.Inset node pointed to by target as first node of the list.\n");
	printf("4.Inset node after a specified node.\n");
	printf("5.Delete first element of the list.\n");
	printf("6.Delete the node after the specified node.\n\n");
	printf("Enter option number :");
	scanf("%d",&choice);
	clrscr();

	node* head;
	head=(node*)malloc(sizeof(node));
	init_l(&head);
	create_list(&head);

	clrscr();
	node* n1;
	n1=(node*)malloc(sizeof(node));
	int num;
	if(choice==3 || choice==4){
		printf("Enter value value of node to be inserted :");
		scanf("%d",&num);
		create_node(n1,num);
	};

	clrscr();
	node* cur;
	cur=(node*)malloc(sizeof(node));
	if(choice==2 || choice==4 || choice==6){
		display(head);
		int pos;
		printf("Enter pos at which current will point :");
		scanf("%d",&pos);
		cur=head;
		while(pos--){
			if(cur==NULL){
				printf("Pointer is invalid");
				break;};
			cur=cur->next;
		};
	};

	clrscr();
	switch(choice){
		case 1: if(empty_l(head)==1){printf("List is empty.\n");}
			  else{printf("List is not empty.\n");};
			  break;
		case 2: if(atend_l(cur)==1){printf("Last node reached\n");}
			  else{printf("Last node not reached\n");};
			  break;	
		case 3: insert_front(n1,&head);
			  display(head);
			  break;
		case 4: insert_after(n1,cur);
			  display(head);
			  break;
		case 5: delete_front(&head);
			  display(head);
			  break;
		case 6: delete_after(cur);
			  display(head);
			  break;
		
	};
	return 0;
};

