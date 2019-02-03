#include <stdio.h>
#include <stdlib.h>
#define size 1000
//void display(char *);

//Create a string
void create_string(char** s){
	printf("Enter string :");
	int i=0;
	char chr;
	*s=(char*)malloc(sizeof(char)*1);
	scanf(" %c",&chr);
	*(*s+i)=chr;
	i++;
	*s=(char*)realloc(*s,sizeof(char)*(i+1));
	while(1){
		scanf("%c",&chr);
		*(*s+i)=chr;
		i++;
		if(chr=='\n'){break;};
		*s=(char*)realloc(*s,sizeof(char)*(i+1));
		
	};
	*(*s+i+1)='\0';
};

//Find length of string
int length_string(char* s){
	int length=0;
	while(s[length]!='\0'){
		length++;
	};
	return length-1;
};

//Compare two strings
void compare_strings(char* s1,char* s2){
	if(length_string(s1)!=length_string(s2)){
		printf("Strings are different\n");
		return;
	}
	else{
		for(int i=0;i<length_string(s1);++i){
			if(s1[i]!=s2[i]){
				printf("Strings are different\n");
				return;
			}
		};
		printf("Strings are equal\n");
		return;
	};
};

//Concatenate 2 strings
void concatenate_strings(char* s1,char* s2,char** s3){
	int len1,len2;
	len1=length_string(s1);
	len2=length_string(s2);
	*s3=(char*)malloc(sizeof(char)*(len1+len2));

	for(int i=0;i<len1;++i){
		*(*s3+i)=s1[i];
	};
	for(int i=0;i<len2;++i){
		*(*s3+len1+i)=s2[i];
	};
};

//Copy a string into another one
void copy_string(char* s1,char** s2){
	int len=length_string(s1);
	*s2=(char*)malloc(sizeof(char)*len);
	for(int i=0;i<len;++i){
		*(*s2+i)=s1[i];
	};
};

//Search for a particular substring in a string
void search_substring(char* s){
	int len1,len2,flag;
	char* sub;
	flag=0;
	
	printf("Creating a sub-string \n");
	create_string(&sub);
	printf("Substring creation completed.\n");
	
	len1=length_string(s);
	len2=length_string(sub);
	
	for(int i=0;i<len1-len2+1;++i){
		for(int j=0;j<len2;++j){
			flag=0;
			if(sub[j]!=s[i+j]){
				flag=1;
				break;
			};
		};
		if(flag==0){printf("Substring found.\n");return;};
	};
	printf("Substring not found.\n");
};

//Find the frequency of letters in a string
void letter_frequency(char* s){
	int ord;
	int f[26];
	char chr;

	for(int i=0;i<26;++i){f[i]=0;};

	for(int i=0;i<length_string(s);++i){
		ord=s[i];
		if (ord>=65 && ord<=90){f[ord-65]++;}
		else if(ord>=97 && ord<=122){f[ord-97]++;}
	};
	for(int i=0;i<26;++i){
		chr=i+97;
		printf("%c :%d\n",chr,f[i]);	
	};
};

//Convert the case of letters in a string
void case_convert(char* s){
	int ord;
	char chr;

	for(int i=0;s[i]!='\0';++i){
		ord=s[i];
		if (ord>=65 && ord<=90){ord=ord+32;chr=ord;s[i]=chr;}
		else if(ord>=97 && ord<=122){ord=ord-32;chr=ord;s[i]=chr;};
	};
};		

//Replace any letter with another one in the string
void replace_letter(char* s){
	char chr1,chr2;

	printf("Enter charecter to replace: ");
	scanf("%c",&chr1);
	printf("Enter charecter to replace with: ");
	scanf(" %c",&chr2);

	for(int i=0;s[i]!='\0';++i){
		if(s[i]==chr1){s[i]=chr2;};
	};
};

//Count the number of words in a string (FAULTY)
int word_count(char* s){
	int count,in,out;
	count=0;
	out=0;
	in=0;

	for(int i=0;s[i]!='\0';++i){
		if(s[i]==' ' || s[i]==',' || s[i]=='.'){in=0;}
		else{in=1;};
		if(out==0 && in==1){count++;};
		out=in;
	};
	return count;
};

// Remove space from the string
void remove_space(char* s,char** s1){
	int j,len;
	len=length_string(s);
	j=0;
	*s1=(char*)malloc(sizeof(char)*len);
	for(int i=0;i<len;++i){
		if(s[i]!=' '){*(*s1+j)=s[i];j++;};
	};
};

//Find the reverse of the string
void reverse_string(char* s,char** s1){
	int len,j;
	len=length_string(s);
	j=0;
	*s1=(char*)malloc(sizeof(char)*len);
	for(int i=len-1;i>=0;--i){
		*(*s1+j)=s[i];j++;
	};
};

//Displays a string
void display(char* s){
	int len=length_string(s);
	for(int i=0;i<len+1;++i){
		printf("%c",s[i]);
	};
	printf("\n");
};

//-------------------------------------------------------------------------------------------------------
//MAIN FUNCTION
int main(){
	int choice;
		
	printf("\n\nSelect option number to carry out the operation:\n");
	printf("1.Find length of string.\n");
	printf("2.Compare two strings.\n");
	printf("3.Concatenate 2 strings.\n");
	printf("4.Copy a string into another one.\n");
	printf("5.Search for a particular substring in a string.\n");
	printf("6.Find the frequency of letters in a string.\n");
	printf("7.Convert the case of letters in a string.\n");
	printf("8.Replace any letter with another one in the string.\n");
	printf("9.Count the number of words in a string.\n");
	printf("10.Remove space from the string.\n");
	printf("11.Find the reverse of the string.\n\n");
	printf("Enter option number :");
	scanf("%d",&choice);
	
	int len,len1;
	char* s;
	char* s1;
	char* s2;
	
	create_string(&s);

	if(choice>=2 && choice<=3){
		create_string(&s1);
	};

	switch(choice){
		case 1: printf("Length :%d\n",length_string(s));
			break;
		case 2: compare_strings(s,s1);
			break;	
		case 3: concatenate_strings(s,s1,&s2);
			printf("Ans :");display(s2);
			break;
		case 4: copy_string(s,&s1);
			printf("Ans :");display(s1);
			break;
		case 5: search_substring(s);
			break;
		case 6: letter_frequency(s);
			break;
		case 7: case_convert(s);
			printf("Ans :");display(s);
			break;
		case 8: replace_letter(s);
			printf("Ans :");display(s);
			break;	
		case 9: printf("Number of words :%d\n",word_count(s));break;
		case 10: remove_space(s,&s1);
			 printf("Ans :");display(s1);
			 break;
		case 11: reverse_string(s,&s1);
			 printf("Ans :");display(s1);
			 break;		
	};
	return 0;
};
