#include <stdio.h>
#include <string.h>

//RETURNS THE NAMES WITH MAX AND MIN LENGTH
void maxmin(){
	FILE* fp;
	char name[100];
	long int max=0;
	long int min=100;
	char maxname[100];
	char minname[100];
	fp=fopen("p5.txt","r");
	for(int i=0;i<54;++i)
	{
		fgets(name,100,fp);
		if(strlen(name)<min)
		{
			min=strlen(name); 
			strcpy(minname,name);
		}
		if(strlen(name)>max)
		{
			max=strlen(name); 
			strcpy(maxname,name);
		}
	}
	
	fclose(fp);
	printf("Smallest name %ld :%s",min-1,minname);
	printf("Largest name %ld :%s",max-1,maxname);
}

//BASIC SORTING 
void wordinsertSort(int m,char a[56][30]){
	char temp[30];
	for(int i=0;i<m;++i){
		for(int j=i+1;j<m;++j){
			if(strcmp(a[j],a[i])<0){
				strcpy(temp,a[j]);
				strcpy(a[j],a[i]);
				strcpy(a[i],temp);
			};
		};
	};
				
};

//CREATING A ALPHABETICALLY SORTED ARRAY
void sortarray(char a[56][30]){
	FILE* fp;
	char name[30];
	fp=fopen("p5.txt","r");
	for(int i=0;i<54;++i){
		fgets(name,30,fp);
		strcpy(a[i],name);
	};
	fclose(fp);
};

//CREATING A ALPHABETICALLY SORTED TEXT FILE
void sortfile(){
	FILE* fp;
	char namearray[56][30];

	sortarray(namearray);
	wordinsertSort(54,namearray);

	fp=fopen("p5_sorted.txt","w");
	for(int i=0;i<54;++i){
		fprintf(fp,"%s",namearray[i]);
	};
	fclose(fp);
};

//MAIN PROGRAM
int main(){
	maxmin();
	//sortfile();
	return 0;
};
