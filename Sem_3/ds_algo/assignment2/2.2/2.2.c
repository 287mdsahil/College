#include<stdio.h>
#include<stdlib.h>
#define max 50
struct cell{
    int i;
    int j;
    float val;
};
struct matrix{
    int beg;
    int end;
};
#include "functions.h"
int main(){
    struct cell c[max];
    struct matrix m[max];
    int freecell=0;
    int freematrix=0;
    while(1)
    {
        system("clear");
        displayAllMatrix(c,m,&freecell,&freematrix);
        int choice=displayMenu();
        switch (choice){
            case 0: takeInput(c,m,&freecell,&freematrix);break;
            case 1: addition(c,m,&freecell,&freematrix);break;
            case 3: const_multiplication(c,m,&freecell,&freematrix);break;
            case 4: transpose_matrix(c,m,&freecell,&freematrix);break;
            case 5: inverse(c,m,&freecell,&freematrix);break;
            case 6: return 0;
            default: break;
        }
    }
    return 0;
}