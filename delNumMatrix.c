#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void print_res(int rows, int cols, int *m){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){

            printf("%2d ", m[i*cols+j]);
        }

        printf("\n");
    }

    printf("\n");
}


int ell_num(int k,int *m,int rig,int col){

    printf("%d ",k);
    printf("\n");
    
    int b[rig*col];
    int s=0,n=0;
    for (int r=0;r<rig;r++){

        for(int c=0;c<col;c++){

            if(k!=m[r*col+c]){
                b[n*col+s]=m[r*col+c];
                s++;
                
            }else{
                b[n*col+s]=0;
                s++;

            }
        }

        n++;
        s=0;
    }
    
    print_res(rig,col,(int*)b);
    return 0;
}

int main(int argc, const char * argv[])
{
    int i=0,j=0;
    int col,rig;
    srand((unsigned)time(NULL));
    printf("inserire il numero di righe e colonne: ");
    scanf("%d %d",&rig,&col);

    while(rig<0||col<0){
        printf("inserire il numero di righe e colonne, corretto: ");
        scanf("%d %d",&rig,&col);

    }

    int a[rig][col];
    for(i=0;i<rig;i++){

        for(j=0;j<col;j++){
            a[i][j]=(int)(rand()%21-10); // va da -10<x<10 (21=10*2+1)
            printf("%d ",a[i][j]);

        }

        printf("\n");

    }

    int k;
    printf("inserire i nuemri che si vogliono azzerare:");
    scanf(" %d",&k);
    ell_num(k,(int*)a,rig,col);

    return 0;
}
