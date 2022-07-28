#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *alloca_vet(int a)
{
    int *p;
    p=calloc(a,sizeof(int));
    return p;
}

int main(int argc, const char * argv[])
{
    int nrig=0,ncol=0,ndep=0,*nrig1,*ncol1,*ndep1;
    int errorig=0,errorcol=0,errordep=0;
    printf("si scriva le dimensioni della matr: \n");
    scanf("%d %d %d",&nrig,&ncol,&ndep);
    nrig1=alloca_vet(nrig);
    ncol1=alloca_vet(ncol);
    ndep1=alloca_vet(ndep);
    if(errorig||errorcol||errordep)
    {
        printf("memoria insufficiente \n");
        return -1;
    }
    errorig=init_vet(nrig1,nrig);
    
    
    
    
    
    
    
}
