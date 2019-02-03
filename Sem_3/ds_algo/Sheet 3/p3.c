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
//--------------------------------------------------------
//Search for a key
node* search(node** head,int key){
	node* cur;cur=(node*)malloc(sizeof(node));
	cur=*head;
	node* prev;prev=(node*)malloc(sizeof(node));
	prev=NULL;
	while(1){
		if(cur->val==key){
			if(prev==NULL){/*delete_front(head);*/return cur;}
			else{/*delete_after(prev);*/printf("%d\n",cur->val);return cur;};
		};
		if(cur->next==NULL){return NULL;};
		prev=cur;
		cur=cur->next;
	};
};

//Find size of list in number of nodes
int size(node* head){
	int s=0;
	node* cur;cur=(node*)malloc(sizeof(node));
	cur=head;
	if(empty_l(head)){return s;};
	while(1){
		if(atend_l(cur)==1){return s;};
		s=s+1;
		cur=cur->next;
	};
};

//Check wether two lists are equal
int check_equal(node* h1,node* h2){
	if(empty_l(h1)==1 && empty_l(h2)==1){return 1;};
	if(size(h1)!=size(h2)){return 0;};
	node* cur1;cur1=(node*)malloc(sizeof(node));cur1=h1;
	node* cur2;cur2=(node*)malloc(sizeof(node));cur2=h2;
	for(int i=0;i<size(h1);++i){
		if(cur1->val!=cur2->val){return 0;};
		cur1=cur1->next;
		cur2=cur2->next;
	};
	return 1;
};

//Print list in reverse order
void display_rev(node* h){
	int s=size(h);
	int* arr;arr=(int*)malloc(sizeof(int)*s);
	node* cur;cur=(node*)malloc(sizeof(node));cur=h;
	for(int i=0;i<s;++i){
		arr[i]=cur->val;
		cur=cur->next;
	};
	printf("[");
	for(int i=0;i<s;++i){printf("%d,",arr[s-1-i]);};
	printf("]\n");
};

//Append a list at the end of another list
void append(node* h1,node* h2){
	if(empty_l(h2)==1){return;};
	int s1=size(h1);
	node* cur;cur=(node*)malloc(sizeof(node));cur=h1;
	for(int i=0;i<s1-1;++i){cur=cur->next;};
	cur->next=h2;
};

//Delete the nth,last and 1st node
void del_node(node** h){
	int n;
	printf("Enter the position to be deleted :");
	scanf("%d",&n);
        int  s=size(*h);
	node* cur;cur=(node*)malloc(sizeof(node));cur=*h;
	for(int i=0;i<s-2;++i){
		if(i==n-1){delete_after(cur);};
		cur=cur->next;
	};
	delete_front(h);
	delete_after(cur);
};

//Check wether list is ordered
int equal(node* h){
	node* cur;cur=(node*)malloc(sizeof(node));cur=h;
	int  s=size(h);
	for(int i=0;i<s-1;++i){
		if(cur->val!=(cur->next)->val){return 0;};
		cur=cur->next;
	};
	return 1;
};

int ascend(node* h){
	node* cur;cur=(node*)malloc(sizeof(node));cur=h;
	int  s=size(h);
	for(int i=0;i<s-1;++i){
		if(cur->val>(cur->next)->val){return 0;};
		cur=cur->next;
	};
	return 1;
};

int descend(node* h){
	node* cur;cur=(node*)malloc(sizeof(node));cur=h;
	int  s=size(h);
	for(int i=0;i<s-1;++i){
		if(cur->val<(cur->next)->val){return 0;};
		cur=cur->next;
	};
	return 1;
};
	
int check_ord(node* h){
	if(equal(h)==1){return 1;}
	else if(ascend(h)==1){return 2;}
	else if(descend(h)==1){return 3;}
	return 0;
};
	
//Merge 2 sorted list
int comp_ord(int s1,int s2,node* h1,node* h2){
	if(s1==s2){
		switch(s1){
			case 0: return 0;
				break;
			case 1: if(h1->val==h2->val){return 1;}return 0;
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

void equal_ascend(node* h1,node* h2,node** h3){
	int s1,s2,i;
	s1=size(h1);s2=size(h2);
	node* cur;cur=(node*)malloc(sizeof(node));cur=h2;
	for(i=0;i<s2;++i){
		if(h1->val<=cur->val){
			for(int j=0;j<s1;++j){ 
				node* target;
				create_node(target,h1->val);
				insert_front(target,h3);
			};break;
		}
		else{insert_front(cur,h3);};
		cur=cur->next;
	};
	if(i<s2-1){
		for(;i<s2;++i){insert_front(cur,h3);cur=cur->next;};
	};
};

void equal_descend(node* h1,node* h2,node** h3){
	int s1,s2,i;
	s1=size(h1);s2=size(h2);
	node* cur;cur=(node*)malloc(sizeof(node));cur=h2;
	for(i=0;i<s2;++i){
		if(h1->val>=cur->val){
			for(int j=0;j<s1;++j){ 
				node* target;
				create_node(target,h1->val);
				insert_front(target,h3);
			};break;
		}
		else{insert_front(cur,h3);};
		cur=cur->next;
	};
	if(i<s2-1){
		for(;i<s2;++i){insert_front(cur,h3);cur=cur->next;};
	};
};

void ascend_both(node* h1,node* h2,node** h3){
	node* cur1;cur1=(node*)malloc(sizeof(node));cur1=h1;
	node* cur2;cur2=(node*)malloc(sizeof(node));cur2=h2;

	while(atend_l(cur1)==0 && atend_l(cur2)==0){
		while(cur1->val<=cur2->val && atend_l(cur1)==0 && atend_l(cur2)==0){
			insert_front(cur1,h3);
			cur1=cur1->next;
		};
		while(cur2->val<=cur1->val && atend_l(cur1)==0 && atend_l(cur2)==0){
			insert_front(cur2,h3);
			cur2=cur2->next;
		};
	};

	if(atend_l(cur1)==1){
		while(atend_l(cur2)==0){insert_front(cur2,h3);cur2=cur2->next;};
	};
	if(atend_l(cur2)==1){
		while(atend_l(cur1)==0){insert_front(cur1,h3);cur1=cur1->next;};
	};
};

void descend_both(node* h1,node* h2,node** h3){
	node* cur1;cur1=(node*)malloc(sizeof(node));cur1=h1;
	node* cur2;cur2=(node*)malloc(sizeof(node));cur2=h2;

	while(atend_l(cur1)==0 && atend_l(cur2)==0){
		while(cur1->val>=cur2->val && atend_l(cur1)==0 && atend_l(cur2)==0){
			insert_front(cur1,h3);
			cur1=cur1->next;
		};
		while(cur2->val>=cur1->val && atend_l(cur1)==0 && atend_l(cur2)==0){
			insert_front(cur2,h3);
			cur2=cur2->next;
		};
	};

	if(atend_l(cur1)==1){
		while(atend_l(cur2)==0){insert_front(cur2,h3);cur2=cur2->next;};
	};
	if(atend_l(cur2)==1){
		while(atend_l(cur1)==0){insert_front(cur1,h3);cur1=cur1->next;};
	};
};
void merger(node* h1,node* h2,int s,node** h3){
	switch(s){
		case 1: ascend_both(h1,h2,h3);break;
		case 2: ascend_both(h1,h2,h3);break;
		case 3: descend_both(h1,h2,h3);break;
		case 4: equal_ascend(h1,h2,h3);break;
		case 5: equal_descend(h1,h2,h3);break;
		case 6: equal_ascend(h2,h1,h3);break;
		case 7: equal_descend(h2,h1,h3);break;
	};
};
node* merge(node* h1,node* h2){
	int ord1,ord2;
	node* h3;h3=(node*)malloc(sizeof(node));
	init_l(&h3);
	ord1=check_ord(h1);
	ord2=check_ord(h2);
	if(comp_ord(ord1,ord2,h1,h2)==0){printf("Lists cannot be merged\n");}
	else{merger(h1,h2,comp_ord(ord1,ord2,h1,h2),&h3);};
	return h3;
};

//Insert a node in the beginning,end and before a specified node
void insert_node(node* h){
	int num,pos;
	node *n1;
	printf("Enter the value for new node: ");
	scanf("%d",&num);
	printf("Enter the position :");
	scanf("%d",&pos);
	create_node(n1,num);
	insert_front(n1,&h);
	node *cur;
	cur=(node*)malloc(sizeof(node));
	cur=h;
	for(int i=0;i<size(h)-1;i++){
		if(i+1==pos){
			insert_after(n1,cur);
		}
		cur=cur->next;
	}
	insert_after(n1,cur);
}

//remove duplicates from a sorted linked list
void remove_dupli_sort(node* h){
	node *cur;
	cur=(node*)malloc(sizeof(node));
	cur=h;
	while(atend_l(cur)==0){
		if(cur->val==cur->next->val){
			delete_after(cur);
		}
		else
			cur=cur->next;
	}
	return;	
}

//remove duplicates fron an unsorted list
void remove_dupli_unsort(node *h){
	node *cur1;
	cur1=(node*)malloc(sizeof(node));
	cur1=h;
	node *cur2;
	cur2=(node*)malloc(sizeof(node));
	while(!atend_l(cur1)){
		cur2=cur1;
		while(!atend_l(cur2)){
			if(cur2->next->val==cur1->val)
				delete_after(cur2);
			cur2=cur2->next;
		}
		cur1=cur1->next;
	}
	return;
}

//Swap elements pairwise
void swap(node** h,int j){
	node* cur1;cur1=(node*)malloc(sizeof(node));cur1=*h;
	node *cur2;cur2=(node*)malloc(sizeof(node));
	node *prev;prev=(node*)malloc(sizeof(node));prev=NULL;
	for(int i=0;i<size(*h);++i){
		cur2=cur1->next;
		if(i==j){
			cur1->next=cur2->next;
			cur2->next=cur1;
			prev->next=cur2;
			break;
		};
		prev=cur1;
		cur1=cur1->next;
	};
};
						
void swap_pair(node** h){
	node *cur1;cur1=(node*)malloc(sizeof(node));cur1=*h;
	int c=0;
	while(atend_l(cur1)==0){
		swap(h,c);
		c=c+2;
		cur1=(cur1->next)->next;
	};
};

//Delete alternate elements
void del_alt(node** h,int n){
	node *cur;cur=(node*)malloc(sizeof(node));
	if(n==1){*h=(*h)->next;};
	cur=*h;
	while(atend_l(cur)==0){
		cur->next=(cur->next)->next;
	};
};
	
//Rotate a list
void rotate(node** h){
	int k,c;
	c=1;
	printf("Enter rotation value :");
	scanf("%d",&k);
	node *cur1;cur1=(node*)malloc(sizeof(node));cur1=*h;
	node *cur2;cur2=(node*)malloc(sizeof(node));
	while(atend_l(cur1)==0){
		if(c==k){cur2=cur1;};
		cur1=cur1->next;
		c++;
	};
	cur1->next=*h;
	*h=cur2->next;
	cur2->next=NULL;
};

//Delete a list
void delete(node** h){
	while(empty_l(*h)==0){
		delete_front(h);
	};
};

//Reverse a list
void rev(node** h){
	node *cur1;cur1=(node*)malloc(sizeof(node));cur1=*h;
	node *cur2;cur2=(node*)malloc(sizeof(node));cur2=NULL;
	while(atend_l(cur1)==0){
		node *cur3;cur3=(node*)malloc(sizeof(node));
		cur3=cur1->next;
		cur1->next=cur2;
		cur2=cur1;
		cur1=cur3;
	};
	*h=cur1;
};

//Sort a list
void sort(node** h){
	//using simple bubble sort
	int s=size(*h);
	for(int i=0;i<s-1;++i){
		node *cur1;cur1=(node*)malloc(sizeof(node));cur1=*h;
		node *cur2;cur2=(node*)malloc(sizeof(node));
		//node *prev;prev=(node*)malloc(sizeof(node));prev=NULL;
		//node *nxt;nxt=(node*)malloc(sizeof(node));nxt=cur2->next;
		for(int j=0;j<s-1-i;++j){
			cur2=cur1->next;
			if(cur1->val>cur2->val){swap(h,j);}
			cur1=cur1->next;
		};
	};
};

//Move last element to front of list
void last_to_first(node** h){
	node *cur1;cur1=(node*)malloc(sizeof(node));cur1=*h;
	node *cur2;cur2=(node*)malloc(sizeof(node));cur2=NULL;
	while(atend_l(cur1)==0){
		cur2=cur1;
		cur1=cur1->next;
	};
	cur2->next=NULL;
	cur1->next=*h;
	*h=cur1;
};	
		
//--------------------------------------------------------
void display_menu(){
	printf("Select option number to carry out the operation:\n");
	printf("1.Search for a key.\n");
	printf("2.Find size of list in number of nodes.\n");
	printf("3.Check wether two lists are equal.\n");
	printf("4.Print list in same order.\n");
	printf("5.Print list in reverse order.\n");
	printf("6.Append a list at the end of another list.\n");
	printf("7.Delete the nth,last and 1st node.\n");
	printf("8.Check wether list is ordered\n");
	printf("9.Merge 2 sorted list\n");
	printf("10.Insert a node in the beginning,end and before a specified node\n");
	printf("11.Remove duplicates from a sorted linked list\n");
	printf("12.Remove duplicates from a unsorted linked list\n");
	printf("13.Swap elements pairwise\n");
	printf("14.Delete alternate nodes\n");
	printf("15.Rotate a list\n");
	printf("16.Delete a list\n");
	printf("17.Reverse a list\n");
	printf("18.Sort a list\n");
	printf("19.Move last element to front of list\n\n");
};
//-------------------------------------------------------------
//MAIN FUNCTION
int main(){
	int choice,key;
	display_menu();
	printf("Enter option number :");
	scanf("%d",&choice);
	clrscr();
	
	if(choice==9){printf("Please ensure that both lists are sorted\n");};
	if(choice==1){printf("Enter key to search for :");scanf("%d",&key);};
	if(choice==11){printf("Please ensure that list is sorted\n");};

	printf("Enter a list\n");	
	node* head1;
	head1=(node*)malloc(sizeof(node));
	init_l(&head1);
	create_list(&head1);

	clrscr();
	node* head2;
	if(choice==3 || choice==6 || choice==9){
		printf("Enter another list\n");	
		head2=(node*)malloc(sizeof(node));
		init_l(&head2);
		create_list(&head2);
		clrscr();
		display(head2);
	};

	display(head1);
	switch(choice){
		case 1: if(search(&head1,key)==NULL){
				printf("Key not found.\n");
			   }
			  else{printf("%d\n",search(&head1,key)->val); };
			  break;
		case 2: printf("Size :%d\n",size(head1));
			  break;	
		case 3: if( check_equal(head1,head2)==1){
				printf("Lists are equal.\n");
			  }
			  else{printf("Lists are not equal.\n");  };
			  break;
		case 4: display(head1);
			  break;
		case 5: display_rev(head1); 
			   break;
		case 6: append(head1,head2);
			  display(head1);
			   break;
		case 7: del_node(&head1);
			  display(head1);
			  break;
		case 8: if( check_ord(head1)>0){
				printf("List is ordered.\n");
			  }
			  else{printf("Lists is not ordered.\n");};
			  break;
		case 9: display(merge(head1,head2));
			  break;
		case 10: insert_node(head1);
			    display(head1);
			    break;
		case 11: remove_dupli_sort(head1);
			    display(head1);
			    break;
		case 12: remove_dupli_unsort(head1);
			    display(head1);
			    break;
		case 13: swap_pair(&head1);
			    display(head1);
			    break;
		case 14: printf("Enter 0 for even,1 for odd elements :");
			    scanf("%d",&choice);
			    del_alt(&head1,choice);
			    display(head1);
			    break;
		case 15: rotate(&head1);
			    display(head1);
			    break;
		case 16: delete(&head1);
			    display(head1);
			    break;
		case 17: rev(&head1);
			    display(head1);
			    break;
		case 18: printf("Enter 0 for  ascending order ,1 for desceding order :");
			    scanf("%d",&choice);
			    sort(&head1);
			    if(choice==1){rev(&head1);};
			    display(head1);
			    break;
		case 19: last_to_first(&head1);
			    display(head1);
			    break;
		
	};
	return 0;
};
