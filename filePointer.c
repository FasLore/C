#include <stdio.h> 
int main()
{
FILE *FP;
char Ch;
    if ((FP=fopen("prova.rtf","r"))!=NULL)
    {
    Ch=getc(FP);
        while (Ch!=EOF)
        {
        putchar(Ch);
        Ch=getc(FP);
        }/* end while */
    fclose(FP);
    }// chiusura del file }/* end if */
    else
        printf("Errore nell’apertura in lettura del file");
} /* end main */
