#include <stdio.h>
#include<stdlib.h>
#include <time.h>

int main(int argc, const char * argv[])
{
    int **matrix;
    int i,j;
    int dim;
    srand((unsigned)time(NULL));
    printf ("Dimensione della matrice: ");
    scanf ("%d",&dim);
    matrix = (int**) malloc(dim*dim*sizeof(int));
    for (i=0; i<dim; i++)
        matrix[i] = (int*) malloc(dim*sizeof(int));
    
    for (i=0; i<dim; i++)
        for (j=0; j<dim; j++)
        {
            matrix[i][j]=(int)(rand()%21-10);
        }
    printf("La matrice e':\n");
    
    for(i = 0; i <dim; i++)
    {
        for(j = 0; j <dim; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    free(matrix);

    return 0;
}
