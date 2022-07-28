#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void print_res(int rows, int cols, int *m)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%2d ", m[i*cols+j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(int argc, const char * argv[])
{
    //matrice di dimensione dim con numeri a random
    int dim;
    printf("inserire la dimensione della matrice: ");
    scanf("%d",&dim);
    srand((unsigned)time(NULL));
    int a[dim][dim];
    int i;
    printf("A: \n");
    for(i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            a[i][j]=(int)(rand()%21-10); //-10<x<10
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    // effetture la trasposta
    int b[dim][dim];
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            b[i][j]=a[j][i];
        }
    
    }
    printf("trasposta: \n");
    print_res(dim,dim,(int*)b);
    
    
    
    
    
    
    return 0;
}
