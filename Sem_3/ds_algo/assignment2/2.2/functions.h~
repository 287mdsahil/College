int displayMenu(){
	printf("MENU:\n");
	printf("0. Input\n");
	printf("1. Addition\n");
	printf("2. Multiplication\n");
	printf("3. Constant multiplication\n");
	printf("4. Transpose\n");
	printf("5. Inverse\n");
	printf("6. Exit\n");
	printf("\nEnter Choice: ");
	
	int choice;
	scanf(" %d",&choice);
	return choice;
}

float returnValue(int x,int y,int id,struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	for(int i=m[id].beg;i<m[id].end;i++){
		if(c[i].i==x && c[i].j==y)
			return c[i].val;
	}
	return 0;
}

void displayAllMatrix(struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	printf("Available matrices:\n\n");
	if(*freematrix==0){
		printf("Empty!!!\n\n");
	}
	for(int id=0;id<*freematrix;id++){
		int x=c[m[id].beg].i;
		int y=c[m[id].beg].j;

		printf("id= %d\n",id);
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++)
				printf("%f ",returnValue(i,j,id,c,m,freecell,freematrix));
			printf("\n");
		}
		printf("\n\n");
	}
}

void swapCells(struct cell *c1, struct cell *c2){
	struct cell dummy=*c1;
	*c1=*c2;
	*c2=dummy;
}
void cellSort(int id,struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	int beg=m[id].beg;
	int end=m[id].end;
	int min;
	for(int i=beg+1;i<end-1;i++){
		min=i;
		for(int j=i+1;j<end;j++){
			if(c[min].i>c[j].i)
				min=j;
			else if(c[min].i==c[j].i && c[min].j>c[j].j)
				min=j;
		}
		swapCells(&c[i],&c[min]);
	}
}

void takeInput(struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	system("clear");
	
	m[(*freematrix)].beg=(*freecell);
	
	printf("Enter the size (m n t): ");
	int x,y;
	float z;
	scanf(" %d %d %f",&x,&y,&z);
	c[(*freecell)].i=x;
	c[(*freecell)].j=y;
	c[(*freecell)].val=z;
	
	m[(*freematrix)].end=(*freecell)+z+1;
	(*freecell)=(*freecell)+1;
	
	for(int i=0;i<z;i++){
		printf("Enter the non zero cells of the sparse matrix(i j val):\n");
		int xx,yy;
		float zz;
		scanf(" %d %d %f",&xx,&yy,&zz);
		if(xx>=x || yy>=y){
			printf("Invalid index!\n");
			i--;
			continue;
		}
		else if(returnValue(xx,yy,*freematrix,c,m,freecell,freematrix)!=0){
			printf("Cell already occupied!\n");
			i--;
			continue;
		}
		else if(zz!=0){
			
			c[*freecell].i=xx;
			c[*freecell].j=yy;
			c[*freecell].val=zz;
			(*freecell)=(*freecell)+1;
		}
	}
	cellSort(*freematrix,c,m,freecell,freematrix);
	(*freematrix)=(*freematrix)+1;
	return;
}

void add(int id1, int id2,struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	m[*freematrix].beg=(*freecell);
	int beg=(*freecell);
	int x,y,z;
	x=c[m[id1].beg].i;
	y=c[m[id1].beg].j;
	c[*freecell].i=x;
	c[*freecell].j=y;
	c[*freecell].val=0;
	(*freecell)=(*freecell)+1;

	for(int i=m[id1].beg;i<m[id1].end;i++){
		struct cell dummy;
		dummy.i=c[i].i;
		dummy.j=c[i].j;
		dummy.val=c[i].val+returnValue(c[i].i,c[i].j,id2,c,m,freecell,freematrix);
		c[*freecell]=dummy;
		(*freecell)=(*freecell)+1;
	}
	for(int i=m[id2].beg;i<m[id2].end;i++){
		struct cell dummy;
		dummy.i=c[i].i;
		dummy.j=c[i].j;
		dummy.val=c[i].val;
		int x=returnValue(c[i].i,c[i].j,id1,c,m,freecell,freematrix);
		if(x!=0)
			continue;
		else{
			c[*freecell]=dummy;
			(*freecell)=(*freecell)+1;
		}
	}
	m[*freematrix].end=(*freecell);
	(*freematrix)=(*freematrix)+1;
	return;
}
void addition(struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	system("clear");
	displayAllMatrix(c,m,freecell,freematrix);

	int id1,id2;
	printf("Enter the id of the first matrix: ");
	scanf(" %d",&id1);
	printf("Enter the id of the second matrix: ");
	scanf(" %d",&id2);

	if(id1>=*freematrix || id2>=*freematrix){
		printf("Invalid ID ");
		getchar();
		getchar();
		return;
	}
	
	if(c[m[id1].beg].i!=c[m[id2].beg].i || c[m[id1].beg].j!=c[m[id2].beg].j){
		printf("Dimension mismatch ");
		getchar();
		getchar();
		return;
	}
	add(id1,id2,c,m,freecell,freematrix);
	return;
}




void const_multiply(int id,float cc, struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	m[*freematrix].beg=*freecell;
	
	c[*freecell]=c[m[id].beg];
	(*freecell)=(*freecell)+1;

	for(int i=m[id].beg+1;i<m[id].end;i++){
		struct cell dummy;
		dummy=c[i];
		(dummy.val)*=cc;
		c[*freecell]=dummy;
		(*freecell)=(*freecell)+1;
	}
	m[*freematrix].end=*freecell;
	(*freematrix)=(*freematrix)+1;
	return;
}
void const_multiplication(struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	system("clear");
	displayAllMatrix(c,m,freecell,freematrix);

	int id;
	float cc;
	printf("Enter the id of the matrix: ");
	scanf(" %d",&id);
	if(id>=*freematrix){
		printf("Invalid ID ");
		getchar();
		getchar();
		return;
	}
	printf("Enter the constant: ");
	scanf(" %f",&cc);

	const_multiply(id,cc,c,m,freecell,freematrix);
	return;
}

void transpose(int id,struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	m[*freematrix].beg=*freecell;
	for(int i=m[id].beg;i<m[id].end;i++){
		struct cell dummy;
		dummy.i=c[i].j;
		dummy.j=c[i].i;
		dummy.val=c[i].val;
		c[*freecell]=dummy;
		(*freecell)=(*freecell)+1;
	}
	m[*freematrix].end=*freecell;
	cellSort(*freematrix,c,m,freecell,freematrix);
	(*freematrix)=(*freematrix)+1;
	return;
}
void transpose_matrix(struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	system("clear");
	displayAllMatrix(c,m,freecell,freematrix);

	int id;
	printf("Enter the id of the matrix: ");
	scanf(" %d",&id);
	if(id>=*freematrix){
		printf("Invalid ID ");
		getchar();
		getchar();
		return;
	}
	transpose(id,c,m,freecell,freematrix);
	return;
}

void inverse(struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	system("clear");
	displayAllMatrix(c,m,freecell,freematrix);
	printf("Under progress!!(press any key to continue)");
	getchar();
	getchar();
}




void rowMultiply(int *row,int id2,int id3,struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	
	return;
}

void multiply(int id1,int id2, struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	transpose(id2,c,m,freecell,freemtarix);
	id2=(*freematrix)-1;
	
	m[*freematrix].beg=(*freecell);
	int id3=*freematrix;
	int row[max];
	int y=0;
	for(int i=m[id1].beg;i<m[id].end;i++)
	{
		if(t[i].i!=t[i+1].i || i==m[id].end-1){
			row[y]=-1;
			y=0;
			rowMultiply(row,id2,id3,c,m,freecell,freematrix);
		}
		else{
			row[y]=i;
			y++;
		}
	}	
	return;
}
void multiplication(struct cell *c, struct matrix *m, int *freecell, int *freematrix){
	system("clear");
	displayAllMatrix(c,m,freecell,freematrix);

	int id1,id2;
	printf("Enter the id of the first matrix: ");
	scanf(" %d",&id1);
	printf("Enter the id of the second matrix: ");
	scanf(" %d",&id2);
	if(id1>=*freematrix || id2>=*freematrix){
		printf("Invalid ID ");
		getchar();
		getchar();
		return;
	}

	multiply(id1,id2,c,m,freecell,freematrix);
	return;
}
