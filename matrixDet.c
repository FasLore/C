#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


int riduz(int dim,int a[][dim],int rig,int col,int b[dim-1][dim-1])
{
    int m=0,n=0;
    for(int p=0;p<dim;p++)
    {
        if(p!=rig&&m<dim-1)
        {
            for(int q=0;q<dim;q++)
            {
                if(q!=col&&n<dim-1)
                {
                    b[m][n]=a[p][q];
                    n++;
                }
            }
            
            m++;
            n=0;
        }
    }

    return 0;

}

int det(int dim,int a[][dim])
{
    int deter;
    int j=0;
    int *peppo=malloc(j*sizeof(int));
    int *gian=malloc(j*sizeof(int));
    
    
    if(dim==1)
        {
            deter=a[0][0];
            printf("il valore in det del det è: %d \n",deter);
            return deter;
        }
    if(dim==2)
    {
        deter=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
        printf("il valore del det della sotmatrix è: %d \n",deter);
        return deter;
    }
    int i=0;
    while(i<dim)
    {
        int b[dim-1][dim-1];
        riduz(dim,a,0,i,b);
        peppo[i]=det(dim-1,b);
        i++;
        j++;
        peppo=realloc(peppo,j*sizeof(int));
    }
    for(int k=0;k<j;k++)
    {
        int sommatoria;
        sommatoria=(pow(-1,k)*a[0][k]*peppo[k]);
        gian[k]=sommatoria;
        gian=realloc(gian,k*sizeof(int));
        printf("a[0][%d]= %d * peppo[%d]=%d\n",k,a[0][k],k,peppo[k]);
    }
    for(int g=0;g<j;g++)
    {
        int sommatoria;
        sommatoria=sommatoria+gian[g];
        deter=sommatoria;
        printf("gian[%d]=%d\n",g,gian[g]);
    }
    
    printf("il valore del det è: %d \n",deter);
    
    return deter;

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
    
    //calcolo del determinate
    
    det(dim,a);
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
