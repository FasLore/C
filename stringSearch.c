//  controllo se in un file di testo ci sono determinate parole, e scrivere nel file di output quali parole sono state trovate quante volte.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cerca(const char *testo,const char *parl, int a)
{
    for( ;*parl!='\0';a++,parl++)
    {
        if(*(testo+a)!=*parl)
        {
            return 1; //true
        }
    }
    return 0;//false
}





int main(int argc, const char * argv[])
{
    FILE *fo;
    if(argc!=4)
    {
        printf("errore \n");
        return(EXIT_FAILURE);
    }
    if((fo=fopen(argv[1],"r+"))==NULL){
        printf("errore nell'apertura del file \n");
        return(EXIT_FAILURE);
    }
    FILE *fout;
    if((fout=fopen(argv[2],"w"))==NULL){
        printf("errore nell'apertura del file \n");
        return(EXIT_FAILURE);
    }


            int a;
            int cont=0;
            char parl[30];
            sprintf(parl,"%s",argv[3]);
            char testo[300];
            while((fgets(testo,300,fo))!=NULL)
            {
                for(a=0;testo[a]!='\0';a++)
                {
                    if(testo[a]==parl[0])
                    {
                        for(int c=1;*parl!='\0';a++,c++)
                        {
                            if(cerca(testo,parl,a)==0)
                            {
                                cont++;
                            }
                        }
                    }
                }
            }
            //printf("cont: %d",cont);
            if(cont==0)
            {
                fprintf(fout,"non esiste '%s' parola nel file \n",argv[3]);
            }
            else
            {
                fprintf(fout,"la parola '%s' è stata trovata %d volte nel file. \n ",argv[3],cont);
            }
            



        fclose(fout);


    fclose(fo);
    
return 0;
}
