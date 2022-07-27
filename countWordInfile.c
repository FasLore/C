#include <stdio.h>
#include <stdlib.h>

typedef enum{FALSO,VERO}BOOLEAN;
/*prototipo di funzione*/
BOOLEAN test(int c)
{
    BOOLEAN ris;
    ris=(c==' ')||(c=='\t')||(c=='.')||(c==';')||(c==',');

    return ris;/*ritorna VERO o FALSO*/

}/*fine della funzione test*/


int main(int argc, const char * argv[])
{
    int c;/*carattere*/
    int d;/*locazione penultimo carattere*/
    int nParole=0;/*contatore parole*/
    int nLinee=0;/*contatore linee*/
    int nCaratteri=0;/*contatore caratteri*/
    BOOLEAN is=0,fineParola=VERO;/**/
    FILE *fp;/*creo un puntatore a un file*/

    /*apri il file, se non puo' essere aperto esci dal programma*/
    if((fp=fopen("C:\\Users\\Lorenzo Fasiello\\CLionProjects\\count_word_infile\\text.txt", "r+"))==NULL)
    {
        printf("Il file non puo' essere aperto. \n");
    }else{
        c=fgetc(fp);/*prende un carattere dal file e lo salva in c*/
        ++nCaratteri;/*incrementa il numero di caratteri*/
        /*se il carattere e' un EOF esci*/

        while(c!=EOF){
            fineParola=VERO; /*inizializzo fine parola a TRUE*/
            /*leggi i caratteri di una linea e individua le parole*/
            while(c!='\n'){
                /*verifica se il carattere letto e' un separatore*/
                is=test(c);
                /*se il carattere e' un separatore e l'ultima parola non e' terminata incrementa il numero di parole*/
                if(is&&!fineParola){
                    nParole++;
                    fineParola=VERO;
                }

                /*altrimenti se il carattere letto non e' un separatore assegna a fineParola FALSO*/
                else if(!is){
                    fineParola=FALSO;

                }
                /*salva il penultimo carattere in d*/
                d=c;
                c=fgetc(fp);/*legge un carattere dal file e lo salva in c*/
                ++nCaratteri;/*incrementa nCaratteri*/

            } /*fine del comando while*/

            ++nLinee;/*incrementa nLinee*/
            is=test(d);/*controlla che il penultimo carattere sia un separatore*/
            /*se non e' un separatore incrementa nParole*/
            if(!is){
                nParole++;
            }
            /*se la parola e' terminata ed e' un separatore incrementa nParole*/
            else
            if(is&&!fineParola){
                nParole++;

            }

            c=fgetc(fp);
        }/*fine del comando while*/
        /*stampa il numero di parole, di caratteri e di linee*/
        printf("Le parole sono=%d \n",nParole);
        printf("I caratteri sono=%d \n",nCaratteri);
        printf("Le linee sono=%d \n",nLinee);
        fclose(fp);/*il file viene chiuso*/

    }
    system("PAUSE");
    return 0;
}
