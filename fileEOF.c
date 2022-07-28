//  Scrivere un programma in linguaggio C che legge un file di testo e scrive un file risultato uguale al file di input nel quale ogni occorrenza 
//  della lettera ‘a’ viene sostituita dalla lettera ‘A’. Il nome del file di input e il nome del file di output sono passati al programma tramite linea di comando.
//  Il programma deve gestire correttamente il caso in cui il nome del file di input specificato è errato e il caso in cui non è possibile scrivere all’interno del 
//  file di output.

#include <stdio.h>
#include <stdlib.h>



int main(int argc, const char * argv[])
{
    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Errore nell'apertura del file %s\n", argv[1]);
        return 0;
    }
    FILE *fp1;
    if ((fp1 = fopen(argv[2], "w")) == NULL)
    {
        printf("Errore nell'apertura del file %s\n", argv[2]);
        return 0;
    }
    char c=getc(fp);
    while (c!=EOF)
    {
       if(c=='a')
       {
           c='A';
       }
    putc(c,fp1);
    }
    return 0;
}
