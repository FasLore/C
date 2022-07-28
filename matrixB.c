#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, const char * argv[])

{   int dim=8;
    srand((unsigned)time(NULL));
    int a[(dim*dim)+2];
    int i=0;
    printf("A: \n");
    for(i=2;i<((dim*dim)+2);i++)
    {
        a[i]=(int)(rand()%100);
            printf("%d ",a[i]);
        
        printf("\n");
    }
    a[0]=dim;
    a[1]=dim;
    FILE *fp;
    fp=fopen("matrixbinario","wb");
    fwrite(a,sizeof(int),dim*dim+2,fp);
    fclose(fp);
    return 0;
}
