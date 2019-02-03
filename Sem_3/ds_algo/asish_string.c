#include<stdio.h>
#include<stdlib.h>

typedef char* string;

string strInit();
int strLen(string s);
void print(string s);
string copy(string* str,string* res);
int freq(char c,string s);
string rev(string str);
string converCase(string str);
string concatinate(string a, string b);
int countWords(string s);
string replaceAt(int pos,char val,string s);
string removeSpace(string s);
int strcmp(string s1, string s2);

int main(){
  string s[1000];
  int type;
  //instructions
  print("Lets play string\n");
  print("Enter the following numbers to do the corresponding operations\n");
  print("1 to enter a string");
  print("2,i to get the length of ith string");
  print("3,i,j to compare i and jth strings");
  print("4,i,j to concatinate i and jth strings");
  print("5,i,j to copy ith string into jth string");
  print("6 to enter a string");
  print("7,i,(char) to find frequency of char in ith string");
  print("8,i to convert cases of ith string");
  print("9,i,j,(char) to replace jth character of ith string with char");
  print("10,i to count no. of words in ith string");
  print("11,i to remove spaces from ith string");
  print("12,i to find the reverse of ith string");
  //operations
  int i=0;
  while(scanf("%d",&type)){
      if(type==1){
          s[i++] = strInit();
      }
      if(type==2){
          int x;
          scanf(",%d",&x);
          printf("%d\n",strLen(s[x]));
      }
      if(type==3){
          int x,y;scanf(",%d,%d",&x,&y);
          printf("%d\n", strcmp(s[x],s[y]));
      }
      if(type==4){
          int x,y;scanf(",%d,%d",&x,&y);
          s[i++] = concatinate(s[x],s[y]);
      }
      if(type==5){
          int x,y;scanf(",%d,%d",&x,&y);
          copy(&s[x],&s[y]);
      }
      if(type==7){
          int x;char y;scanf(",%d,%c",&x,&y);
          printf("%d\n",freq(y,s[x]));
      }
      if(type==8){
          int x;
          scanf(",%d",&x);
          s[x] = converCase(s[x]);
      }
      if(type==9){
          int x,pos;char val;scanf(",%d,%d,%c",&x,&pos,&val);
          s[x] = replaceAt(pos,val,s[x]);
      }
      if(type==10){
          int x;scanf(",%d",&x);
          printf("%d\n",countWords(s[x]));
      }
      if(type==11){
          int x;scanf(",%d",&x);
          s[x] = removeSpace(s[x]);
      }
      if(type==12){
          int x;scanf(",%d",&x);
          s[x] = rev(s[x]);
      }
      int j;
      for(j=0;j<i;j++){printf("%d -> ",j);print(s[j]);}
      printf("\n");
  }
  return 0;
}

int strLen(string str){
  int len;
  for (len = 0;;++len) if (str[len]==0) return len;
}

string strInit(){
    int n = 1,cnt=0;
    scanf("\n");
    string res = (char*)malloc(n*sizeof(char));
    char c;
    while((c=getchar()) != '\n'){
        if(cnt>n)
            res = realloc(res, (n += 10) * sizeof(char));
        res[cnt++] = c;
    }
    return res;
}

void print(string s){
  printf("%s",s);
  printf("\n");
}

string copy(string* str,string* res){
  int i,n = strLen(*str);
  *res = (char*)malloc((n+1)*sizeof(char));
  char* ptr = *res;char* ptr2 = *str;
  while(**str != '\0'){
    **res = **str;
    (*res)++;
    (*str)++;
  }
  **res = '\0';
  *res = ptr;
  *str = ptr2;
  return *res;
}

int freq(char c,string s){
  int cnt = 0;
  while(*s != '\0'){
    cnt += (*s==c);
    s++;
  }
  return c;
}

string rev(string str){
  int i,n = strLen(str);
  string res = (char*)malloc((n+1)*sizeof(char));
  char* ptr = res;
  for(i=n-1;i>=0;i--){
    *res = str[i];
    res++;
  }
  *res = '\0';
  return ptr;
}

string converCase(string str){
  int i,n = strLen(str);
  string res = (char*)malloc((n+1)*sizeof(char));
  char* ptr = res;
  while(*str != '\0'){
    //printf("%c ", str[i]);
    if(*str>='A' && *str<='Z'){
      *res = (char)(*str+32);
    }
    else if(*str>='a' && *str<='z'){
      *res = (char)(*str-32);
    }
    else *res = *str;
    res++;str++;
  }
  *res = '\0';
  return ptr;
}

string concatinate(string a, string b){
    string c = (char*)malloc((strLen(a)+strLen(b)+1)*sizeof(char));
    char* ptr = a;char* res = c;
    while(*ptr != '\0'){
        *res = *ptr;
        res++;
        ptr++;
    }
    ptr = b;
    while(*ptr != '\0'){
        *res = *ptr;
        res++;
        ptr++;
    }
    *res = '\0';
    return c;
}

int countWords(string s){
    int cnt = ((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z'))?1:0;
    char* ptr = s;
    while(*ptr != '\0'){
        if(*ptr == ' ')cnt++;
        ptr++;
    }
    return cnt;
}

string replaceAt(int pos,char val,string s){
    if(pos>strLen(s)){
        printf("The position doesn't exist\n");
        return s;
    }
    string res = (char*)malloc((strLen(s)+1)*sizeof(char));
    char* ptr = res;int i=1;
    while(*s != '\0'){
        if(i==pos) *ptr = val;
        else *ptr = *s;
        ptr++;s++;i++;
    }
    return res;
}

string removeSpace(string s){
    char* ptr = s;int spaceCnt = 0;
    while(*ptr != '\0'){if(*ptr == ' ')spaceCnt++;ptr++;}
    string res = (char*)malloc((strLen(s)+1-spaceCnt)*sizeof(char));
    ptr = s;char* ans = res;
    while(*ptr != '\0'){
        if(*ptr == ' ')ptr++;
        else{
            *res = *ptr;
            res++;ptr++;
        }
    }
    return ans;
}

int strcmp(string s1, string s2){
    while (*s1 == *s2 && *s1++ | *s2++);
    return *s1 - *s2;
}
