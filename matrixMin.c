#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, const char * argv[]){
    int Nrig;
    int Ncol;
    int i=0,j=0;
    int k=0;int minj;
    srand((unsigned)time(NULL));
    printf("inserire il numero di righe: ");
    scanf("%d",&Nrig);
    printf("inserire il numero di colonne: ");
    scanf("%d",&Ncol);
    int v[Nrig][Ncol];
    int cont;
    for(i=0;i<Nrig;i++) //riempio una matrice di numeri a random di nrig e ncol con numeri da 0 a 100
    {
        for(j=0;j<Ncol;j++)
        {
            v[i][j]=(int)(rand()%100);
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<Nrig;i++) //controllo nella prima e successive righe qual è il minimo
    {
        int minr=v[i][0];
        for(j=1;j<Ncol;j++)
        {
            if(minr>v[i][j])
            {minr=v[i][j];}
            minj=j;
        }
        for(k=0;k<Nrig;k++) //identificato il minimo ti tale riga passo al controllo se è anche il massimo, ossia se è il punto si sella
        {
            if(minr>v[k][minj])
            {
                cont++;
            }
        }
        if(cont==(Nrig-1))
        {printf("il punto di sella è %d che sta nella riga %d \n", minr,(i+1));}
        else {printf("non esiste punto di sella nella riga %d \n",(i+1));}
        cont=0;
        
    }
    return 0;
}
