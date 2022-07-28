#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int stamp_matrix(int rig,int col,int *b)
{
    for (int i = 0; i < rig; i++){

        for (int j = 0; j < col; j++){
            printf("%d ", b[i*col+j]);
        }

        printf("\n");
    }
    return 0;
}

int main(int argc, const char * argv[]){

        srand((unsigned)time(NULL));
        int rig,col;
        printf("scrivi il numero di righe e di colonne della matrice che si desidera: ");
        scanf("%d %d",&rig,&col);
        int a[rig][col];
        int r=0,c=0;
        printf("a: \n");
        for(r=0;r<rig;r++){

            for(c=0;c<col;c++){
                a[r][c]=(int)(rand()%100+1);
                //printf("a[%d][%d] = %d ",r,c,a[r*col+c]);
            }
           // printf("\n");
        }

    
    stamp_matrix(rig,col,(int *)(a));
    
    int i,j;
    printf("inserisci la riga e la colonna che desideri elliminare: ");
    scanf("%d %d",&i,&j);
    if((!(i<rig && 0<=i)) || (!(j<col && 0<=j)))
    {
        printf("errore, incongruenza nei dati di input \n");
        return 1;
    }
    printf("b: \n");
    
    //eliminazione di riga e col
    int b[rig-1][col-1];
    int m=0, n=0;
    for(int p=0;p<rig;p++){

        if(p!=i&&m<rig-1){

            for(int q=0;q<col;q++){

                if(q!=j && n<col-1){
                    b[m][n]=a[p][q];
                    n++;
                }
            }

            m++;
            n=0;
        }
    }
    
    stamp_matrix(rig-1,col-1,(int *)b);
    return 0;
}
