#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define maxdim  3
#define k  2

int filtra_multipli(int a[][maxdim])
{
    int b[maxdim][maxdim];
    int i=0,j=0;
    printf("B: \n");
    for(i=0;i<maxdim;i++){
        for(j=0;j<maxdim;j++){
            if(((a[i][j])%k==0)||(k%(a[i][j])==0)) //a%k multiplo k%a divisore
            {
                b[i][j]=a[i][j];
            }else{
                b[i][j]=0;

            }
            printf("%d ",b[i][j]);

        }
        printf("\n");

    }
    return 0;
}



int main(int argc, const char * argv[])
{
    srand((unsigned)time(NULL));
    int a[maxdim][maxdim];
    int i=0,j=0;
    printf("A: \n");
    for(i=0;i<maxdim;i++)
    {
      for(j=0;j<maxdim;j++)
      {
          a[i][j]=(int)(rand()%100);
          printf("%d ",a[i][j]);
      }
        printf("\n");
    }
    filtra_multipli(a);
    return 0;
}
