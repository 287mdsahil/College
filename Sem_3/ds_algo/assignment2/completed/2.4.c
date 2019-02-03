#include<stdio.h>
#include<stdlib.h>
#include<string.h>



char* stringInput(){
/*	char *str=NULL;*/
/*	int size=0;*/
/*	char c;*/
/*	while(1){*/
/*		c=getchar();*/
/*		if(c=='\n') break;*/
/*		char *str1=realloc(str,sizeof(char)*((size+1)*10));*/
/*		str=str1;*/
/*		str[size]=c;*/
/*		size++;*/
/*	}*/
/*	return str;*/
	int n = 1,cnt=0;
    scanf("\n");
    char* res = (char*)malloc(n*sizeof(char));
    char c;
    while((c=getchar()) != '\n'){
        if(cnt>n)
            res = realloc(res, (n += 10) * sizeof(char));
        res[cnt++] = c;
    }
    return res;
}


int stringLen(char *str){
	int i=0;
	for(i=0;str[i]!='\0';i++);
	return i;
}

int stringCmp(char *s1,char *s2){
	int i=0;
	while(1){
		if(s1[i]=='\0' && s2[i]!='\0')
			return -s2[i];
		else if(s1[i]!='\0' && s2[i]=='\0')
			return s1[i];
		else if(s1[i]=='\0' && s2[i]=='\0')
			return 0;
		else if(s1[i]!=s2[i])
			return s1[i]-s2[i];
		i++;
	}
}

char* stringConcat(char *s1,char *s2){
	char *s=NULL;
	int size=0;
	
	for(int i=0;s1[i]!='\0';i++,size++){
		s=realloc(s,(size+1)*sizeof(char));
		s[size]=s1[i]; 
	}

	for(int i=0;s2[i]!='\0';i++,size++){
		s=realloc(s,(size+1)*sizeof(char));
		s[size]=s2[i]; 
	}
	return s;
}

char* stringCp(char *s2){
	char *s1=NULL;
	int i=0;
	for(i;s2[i]!='\0';i++){
		s1=realloc(s1,(i+1)*sizeof(char));
		s1[i]=s2[i];
	}
	s1[i]='\0';
	return s1;
}

int subStrSearch(char *sub,char *sup){
	for(int i=0;sup[i]!='\0';i++){
		if(sup[i]==sub[0]){
			int j=0,flag=1;
			for(j=0;sub[j]!='\0';j++){
				if(sub[j]!=sup[i+j]){
					flag=0;
					break;
				}
			}
			if(flag==1) return i;
		}
	}
	return -1;
}




int menu(void);
void findLen();
void compareStrings();
void concatenation();
void copy();
void freq();
void caseConvert();
void replaceChar();
void wordCount();
void removeWhiteSpace();
void stringReverse();



int main(){
    //char *s=stringInput();
    while(1){
        system("clear");
        int choice=menu();
        switch(choice){
            case 1: findLen(); break;
            case 2: compareStrings();break;
            case 3: concatenation();break;
            case 4: copy();break;
            case 5: freq();break;
            case 6: caseConvert();break;
            case 7: replaceChar();break;
            case 8: wordCount();break;
            case 9: removeWhiteSpace();break;
            case 10: stringReverse();break;
            case 11: return 0;
        }
    }
    return 0;
}

int menu(void){
    printf("Menu:\n");
    printf("1. Find string length\n");
    printf("2. Compare two strings\n");
    printf("3. Concatenate two strings\n");
    printf("4. Copy a string to another\n");
    printf("5. Find frequency of a letter in a string\n");
    printf("6. Convert the case of letters in a string\n");
    printf("7. Replace any letter with another in a string\n");
    printf("8. count no of words in a string\n");
    printf("9. Remove spaces in a string\n");
    printf("10. Reverse a string\n");
    printf("11. Exit\n");
    int choice;
    printf("Enter the choice: ");
    scanf(" %d",&choice);
    return choice;
}

void findLen(){
    printf("Enter the string: ");
    char *s=stringInput();
    printf("The length of the stirng is : %d\n",stringLen(s));
    getchar();
    return;
}


void compareStrings(){
	printf("Enter the first string: ");
	char *s1=stringInput();
	printf("Enter the second string: ");
	char *s2=stringInput();
	int i=stringCmp(s1,s2);
	if(i>0){
		printf("The second string comes first in the dictionary!");
		getchar();
	}
	else if(i==0){
		printf("Both the strings are equal!");
		getchar();
	}
	else{
		printf("The first string comes first in the dictionary!");
		getchar();
	}
	return;
}

void concatenation(){
	printf("Enter the first string: ");
	char *s1=stringInput();
	printf("Enter the second string: ");
	char *s2=stringInput();
	
	char *s=stringConcat(s1,s2);
	printf("The concatenated string is: %s",s);
	getchar();
	return;
}


void copy(){
	printf("Enter the first string: ");
	char *s1=stringInput();
	printf("Enter the second string: ");
	char *s2=stringInput();
	
	s1=stringCp(s2);
	printf("The strings after being copied are : %s and %s",s1,s2);
	getchar();
	return;
}

void freq(){
	printf("Enter the string :");
	char *s=stringInput();
	char c;
	printf("Enter the character to search for :");
	scanf(" %c",&c);
	int count=0;
	for(int i=0;s[i]!='\0';i++)
		if(s[i]==c) count++;
		
	printf("freq : %d\n",count);
	getchar();
	getchar();
	return;
}

void caseConvert(){
	printf("Enter the string :");
	char *s=stringInput();
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='a' && s[i]<='z')	s[i]=s[i]-'a'+'A';
		else if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
	}
	printf("The string after conversion is : %s",s);
	getchar();
	return;
}

void replaceChar(){
	printf("Enter the string :");
	char *s=stringInput();
	printf("Enter the letter to replace :");
	char c,r;
	scanf(" %c",&c);
	
	
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==c){
			printf("Enter the letter to replace with :");
			scanf(" %c",&r);
			s[i]=r;
			printf("After replacing first ocurrence : %s",s);
			getchar();
			getchar();
			return;
		}
	}
	printf("Character not found!!");
	getchar();
	getchar();
	return;
}

void wordCount(){
	printf("Enter the string :");
	char *s=stringInput();
	int words=0;
	for(int i=1;s[i]!='\0';i++){
		if(s[i]==' ' && s[i-1]!=' ')
			words++;
		if(s[i+1]=='\0') words++;
	}
	printf("The no of words are: %d",words);
	getchar();
	return;
}


void removeWhiteSpace(){
	printf("Enter the string :");
	char *s=stringInput();
	char *s2;
	int l=stringLen(s);
	s2=(char*)malloc(l*sizeof(char));
	int j=0;
	for(int i=0;i<=l;i++){
		if(s[i]!=' '){
			s2[j]=s[i];
			j++;
		}
	}
	s=s2;
	printf("After revoving the white spaces : %s",s);
	getchar();
	return;
}


void stringReverse(){
	printf("Enter the string : ");
	char *s=stringInput();
	
	int l=stringLen(s);
	for(int i=0;i<l/2;i++){
		char dummy=s[i];
		s[i]=s[l-i-1];
		s[l-i-1]=dummy;
	}
	
	printf("After string reversal : %s",s);
	getchar();
	return;
}
