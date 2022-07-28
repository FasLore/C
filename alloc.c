#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]){
    int nrig,ncol,depth;
    int r=0,c=0,d=0;
    int ***m;
    srand((unsigned)time(NULL));
    printf("si scriva in seguito i numeri della matrice a 3 dimensioni: \n");
    scanf("%d %d %d",&nrig,&ncol,&depth);
    m=malloc(nrig*sizeof(**m));//si alloca un array di nrig puntatori e si assegna il puntatore a una variabile
    for(r=0;r<nrig;r++){
        m=malloc(ncol*sizeof(*m));
        for(c=0;c<ncol;c++){
            m[c]=malloc(depth*sizeof(int));
            for(d=0;d<depth;d++){
                m[r][c][d]=((int)rand()%101-50);
                printf("%d ",m[r][c][d]);

            }
            printf("\n");

        }
    }
4


    return 0;
}
