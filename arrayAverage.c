// si ha un vettore di elementi float e dobbimo ottenere un altro vettore di float, tale che l'elemento i-esimo deve essere la media 
//  di due elementi successivi. NON DOBBIAMO USCIRE DAL VETTORE. a=((a+(a+1))/2)

#include <stdio.h>
#include <stdlib.h>

int get_input(float vet[],int l) //siccome il par. formale è stato dichiarato come vettore, il passaggio avviene tramite riferimento
{
    int i;
    for (i=0;i<1;i++)
    {
        scanf("%f", &vet[i]);
    }
    return vet[i];
}
void calcmedia(float vet[], int l) //ora si implementa la funzione ai=((ai+ a(i+1))/2)
{
    int i;
    for (i=0;i<l-1;i++)
    {
        vet[i]=(vet[1]+vet[i+1])/2;
    }
}
void printvet(float vet [], int l)
{
    int i;
    for (i=0;i<1;i++)
    {
        printf("il vettore : %f \n", vet [i]);
    }
}
int main(int argc, const char * argv[])
{
    int size; // allocazione dinamica: il vettore può essere dichiarato a posteriori con una cardinalità    definita a runtime dal 1999
    int err;
    printf(" inserisci size  \n");
    scanf("%d", &size); //capire che abbiamo effettivamente letto un intero (la dobbiamo scrivere noi), verificare che si aun intero senza segno
    float a[size]; //è un vettore automatico, quindi quando chiuderemo la } il vettore verrà  dealocato
    err=get_input(a,size);
    if (err!=0)
    {
        printf("ho un errore\n");
        return 1;
    }
    calcmedia(a,size);
    printvet(a,size);
    return 0;
}
