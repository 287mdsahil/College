#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* decToHexa(int n) 
{    
    // char array to store hexadecimal number 
    char hexaDeciNum[100]; 
      
    // counter for hexadecimal number array 
    int i = 0; 
    while(n!=0) 
    {    
        // temporary variable to store remainder 
        int temp  = 0; 
          
        // storing remainder in temp variable. 
        temp = n % 16; 
          
        // check if temp < 10 
        if(temp < 10) 
        { 
            hexaDeciNum[i] = temp + 48; 
            i++; 
        } 
        else
        { 
            hexaDeciNum[i] = temp + 55; 
            i++; 
        } 
          
        n = n/16; 
    } 
      
    char *res;
    res = (char*) malloc(100*sizeof(char));
    int z=0;
    // printing hexadecimal number array in reverse order 
    for(int j=i-1; j>=0; j--)
    { 
        res[z] =  hexaDeciNum[j];
        z++;
    }

    return (char*)res;
} 


char* reallocate(char *l,char *h,char *start)
{
    //printf("%s%s\n",h,l);
    char a[10];
    strcat(a,h);
    strcat(a,l);
    printf("%s\n",a);
    int add = hex_decimal(a)+hex_decimal(start);
    printf("%d\n",add);
    return decToHexa(add);
}

int main()
{
    char *res;
    res = (char*)malloc(10*sizeof(char));
    res = reallocate("01","00","2000");
    printf("%s\n",res);
    return 0;
}

