#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define abs(x) ((x) > 0) ? (x) : -(x);

int somma_vet(int *vet,int n){
    int i=0,somme=0;
    for(i=0;i<n;i++){
        somme+=abs(vet[i]);

    }
    return somme;
}






int main(int argc, const char * argv[]){
    int nrig,ncol;
    int i=0,j=0;
    int p;
    int cont=0;
    char cnt='s';
    srand((unsigned)time(NULL));
    while ( cnt == 's'){
    printf("inserisci il numero di righe e colonne: ");
    scanf("%d %d",&nrig,&ncol);
    while(nrig!=ncol){
        printf("inserisci il numero di righe e colonne della matrice quadrata: ");
        scanf("%d %d",&nrig,&ncol);

    }
    int v[nrig][ncol];
    for(i=0;i<nrig;i++) // si contruisce una matrice quadrata con -100<x<100
        {
        for(j=0;j<ncol;j++){
            v[i][j]=(int)(rand()%201-(100));
            printf("%d || ",v[i][j]);

        }
        printf("\n");
    }
        if ((nrig==1)&&(ncol==1))
        {
            printf("è digonalemente dominante. \n");
        }else{
    for(i=0;(i<nrig)&&(i<ncol);i++) //si controlla che sia diagonalmente dominate
    {
        int c=abs(v[i][i]);
        p=somma_vet(v[i],nrig);
        if(c>(p-c)){
            cont++;

        }
    }
    if(cont==nrig){
        printf("la matrice è diagonalmente dominante\n");
    }
    else{
        printf("la matrice non è diagonalmente dominante\n");

    }
        }
        printf("Vuoi continuare? (s/n)");
        scanf("\n%c",&cnt);
    }
}
