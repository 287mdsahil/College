#include <stdio.h>
#define size 1000
struct term{
	int row;
	int col;
	int val;
};
struct term term_pool[size];
int mat_pool[size];
int index1=0;  //term_pool counter
int index2=0;  //mat_pool counter
void display(int);

//--------------------ADD MATRICES------------------------
int check_comp(int start1,int start2){
	int x1,x2,y1,y2;
	x1=term_pool[start1].row;
	x2=term_pool[start2].row;
	y1=term_pool[start1].col;
	y2=term_pool[start2].col;
	if(x1==x2 && y1==y2){return 1;}
	return 0;
};
	
void add(int p1, int p2){
	int start1,end1;
	if(p1==1){start1=0;end1=mat_pool[0];}
	else{start1=mat_pool[p1-2]+1;end1=mat_pool[p1-1];};

	int start2,end2;
	if(p2==1){start2=0;end2=mat_pool[0];}
	else{start2=mat_pool[p2-2]+1;end2=mat_pool[p2-1];};

	if(check_comp(start1,start2)==0){
		printf("Invalid entry\n");return;  //checks if 2 matrices are of same shape
	};

	struct term t;
	int org=index1;
	t.row=term_pool[start1].row;
	t.col=term_pool[start1].col;
	t.val=0;
	term_pool[index1]=t;
	index1++;

	struct term check[size];    //Stores position alredy covered as (x,y,some value)
	int count=0;
	for(int i=start1+1;i<end1+1;++i){
		struct term t1;
		struct term t2;
		struct term t3;
		int flag=0;
		t1=term_pool[i];
		for(int j=start2+1;j<end2+1;++j){
			t2=term_pool[j];
			if(t1.row==t2.row && t1.col==t2.col){
				t3.row=t1.row;
				t3.col=t1.col;
				t3.val=t1.val+t2.val;
				flag=1;
				term_pool[index1]=t3;
				index1++;
				check[count]=t1;
				count++;
				term_pool[org].val++;
			};
		};
		if(flag==0){term_pool[index1]=t1;index1++;term_pool[org].val++;}
	};
	
	for(int j=start2+1;j<end2+1;++j){
		struct term t2;
		t2=term_pool[j];
		int flag=0;
		for(int i=0;i<count;++i){
			if(t2.row==check[i].row && t2.col==check[i].col){flag=1;}
		};
		if(flag==0){term_pool[index1]=t2;index1++;term_pool[org].val++;};
	};
	mat_pool[index2]=index1-1;
	index2++;
	display(index2);
};

//----------------------MULTIPLY A CONSTANT TO A MATRIX--------------------------
void mulc(int p1,int c){
	int start,end;
	if(p1==1){start=0;end=mat_pool[0];}
	else{start=mat_pool[p1-2]+1;end=mat_pool[p1-1];};
	
	term_pool[index1]=term_pool[start];
	index1++;
	for(int i=start+1;i<end+1;++i){
		struct term t1;
		struct term t2;
		t1=term_pool[i];
		t2.row=t1.row;t2.col=t1.col;
		t2.val=(t1.val)*c;
		term_pool[index1]=t2;
		index1++;
	};
	mat_pool[index2]=index1-1;
	index2++;
	display(index2);
};

//---------------------------TRANSPOSE A MATRIX---------------------------
void trans(int p1){
	int start,end;
	if(p1==1){start=0;end=mat_pool[0];}
	else{start=mat_pool[p1-2]+1;end=mat_pool[p1-1];};
	
	term_pool[index1]=term_pool[start];
	term_pool[index1].row=term_pool[start].col;
	term_pool[index1].col=term_pool[start].row;
	index1++;
	
	for(int i=start+1;i<end+1;++i){
		struct term t1;
		struct term t2;
		t1=term_pool[i];
		t2.row=t1.col;
		t2.col=t1.row;
		t2.val=t1.val;
		term_pool[index1]=t2;
		index1++;
	};
	mat_pool[index2]=index1-1;
	index2++;
	display(index2);
};
//----------F MULTIPLY 2 MATRICES------------------------------
int check_comp_(int start1,int start2){
	int x1,x2;
	x1=term_pool[start1].col;
	x2=term_pool[start2].col;
	if(x1==x2){return 1;}
	return 0;
};

void uni_row(int mat[size],int s,int e,int* c){
	*c=0;
	for(int i=s;i<e+1;++i){
		int flag=0;
		for(int j=0;j<*c;++j){
			if(mat[j]==term_pool[i].row){flag=1;};
		};
		if(flag==0){mat[*c]=term_pool[i].row;*c=*c+1;};
	};
};

void same_col(int s1,int e1,int s2,int e2,struct term mat[size],int* c){
	*c=0;
	for(int i=s1;i<e1+1;++i){
		for(int j=s2;j<e2+1;++j){
			struct term t1;
			struct term t2;
			t1=term_pool[i];
			t2=term_pool[j];
			if(t1.col==t2.col){
				struct term t;
				t.row=t1.row;
				t.col=t1.col;
				t.val=t2.row;
				mat[*c]=t;
				*c=*c+1;
			};
		};
	};
};

void all_cols(struct term colmat[size],int a,int c,int mat[size],int* c2,int c1){
	*c2=0;
	for(int i=0;i<c1;++i){
		struct term t=colmat[i];
		if(t.row==a && t.val==c){mat[*c2]=t.col;*c2++;};
	};
};

int find(int r,int c,int s,int e){
	for(int i=s;i<e+1;++i){
		if(term_pool[i].row==r && term_pool[i].col==c){
			return term_pool[i].val;
		};
	};
	return 0;
};

void mul(int p1,int p2){
	trans(p2);
	p2=index2;
	
	int start1,end1;
	if(p1==1){start1=0;end1=mat_pool[0];}
	else{start1=mat_pool[p1-2]+1;end1=mat_pool[p1-1];};

	int start2,end2;
	if(p2==1){start2=0;end2=mat_pool[0];}
	else{start2=mat_pool[p2-2]+1;end2=mat_pool[p2-1];};

	if(check_comp_(start1,start2)==0){
		printf("Operation invalid on given input\n"); //checks if 2 matrices are of compatible shape
		return;
	};
	
	struct term t;
	int org=index1;
	t.row=term_pool[start1].row;
	t.col=term_pool[start2].row;
	t.val=0;
	term_pool[index1]=t;
	index1++;

	int mat1[size];
	int mat2[size];
	int c1,c2,c3;
	struct term colmat[size];  //saves positions in (a,b,c) form where a=row in mat1,b=common col,c=row in mat2
	uni_row(mat1,start1+1,end1,&c1);
	uni_row(mat2,start2+1,end2,&c2);
	same_col(start1+1,end1,start2+1,end2,colmat,&c3);

	for(int i=0;i<c1;++i){
		for(int j=0;j<c2;++j){
			struct term t;
			t.row=mat1[i];
			t.col=mat2[j];
			t.val=0;
			int mat3[size];
			int c4=0;
			all_cols(colmat,t.row,t.col,mat3,&c4,c3); //all column values having in(a,b,c) having a,c as required
			for(int k=0;k<c3;++k){
				t.val=t.val+find(t.row,mat3[k],start1+1,end1)*find(t.col,mat3[k],start2+1,end2);
			};
			term_pool[index1]=t;
			index1++;
			term_pool[org].val++;
		};
	};
	mat_pool[index2]=index1-1;
	index2++;
	display(index2);
};
//-------ENTER MATRIx----------------------------------------------------
void read_mat(){
	int n,m,total,num,i,j,start;
	printf("Enter number of rows :");
	scanf("%d",&n);
	printf("Enter number of columns :");
	scanf("%d",&m);
	printf("Enter number of terms :");
	scanf("%d",&total);
	if(total<0 || total>n*m){printf("Invalid entry\n");return;};

	struct term t; //1st tupule storing (n,m,total)
	t.row=n;
	t.col=m;
	t.val=total;
	term_pool[index1]=t;
	index1++;

	printf("ENTER MATRIX\n");
	while(total--){
		printf("Enter row :");
		scanf("%d",&i);
		if(i<0 || i>n){printf("Invalid entry\n");index1--;return;};
		printf("Enter column :");
		scanf("%d",&j);
		if(j<0 || j>m){printf("Invalid entry\n");index1--;return;};
		printf("Enter number :");
		scanf("%d",&num);
		struct term t;
		t.row=i;
		t.col=j;
		t.val=num;
		term_pool[index1]=t;
		index1++;
	};
	mat_pool[index2]=index1-1;
	index2++;	
};
//-----------------------------DISPLAYS-------------------------------------------------
void display(int p1){
	int start,end;
	if(p1==1){start=0;end=mat_pool[0];}
	else{start=mat_pool[p1-2]+1;end=mat_pool[p1-1];};
	
	int m,n,tot;
	m=term_pool[start].row;
	n=term_pool[start].col;
	tot=term_pool[start].val;
	start++;
	printf("-----------------------------------------------------------------\n");
	for(int i=start;i<end+1;++i){
		struct term t=term_pool[i];
		int r,c,v;
		r=t.row;
		c=t.col;
		v=t.val;
		printf("mat%d[%d][%d]:%d \n",p1,r,c,v);
	};
	printf("-----------------------------------------------------------------\n");
	printf("\n");
};

void display_all(){
	for(int i=0;i<index2;++i){
		printf("\t\t\tMatrix %d.\n ",i+1);
		display(i+1);
	};
};
//-------------------------MENU OF FUNCTIONS--------------------------------------------
void menu(){
	display_all();
	int choice;
	printf("\nChoose an option:\n");
	printf("1. Add\n");
	printf("2. Multiply\n");
	printf("3. Multiply with contant\n");
	printf("4. Transpose\n");
	scanf("%d",&choice);
	
	int p1,p2;
	int c;
	
	if(choice==1 ||choice==2){
		printf("Enter matrix numbers :");
		scanf("%d %d",&p1,&p2);
	}
	else{printf("Enter matrix number :");scanf("%d",&p1);};

	switch(choice){
		case 1: add(p1,p2);
			break;
		case 2: mul(p1,p2);
			break;
		case 3: printf("Enter constant :");
			scanf("%d",&c);
			mulc(p1,c);
			break;
		case 4: trans(p1);
			break;
	};
};		
//--------------------------MAIN FUNCTION-----------------------------------------------------
int main(){
	while(1){
		int choice;
		printf("\nPress 0 to exit\n");
		printf("Press 1 to enter a matrix\n");
		printf("Press 2 to display function menu\n\n");
		scanf("%d",&choice);
		
		if(choice==0){break;}
		else if(choice==1){read_mat();}
		else{menu();};
	};
	return 0;
}
