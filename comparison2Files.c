#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    if(argc!=3){
        printf("errore \n");
        return 1;
    }

    FILE *fp1;
    FILE *fp2;
    char c1[120],c2[120];
    int notequal=0;
    fp1=fopen(argv[1],"r");
    fp2=fopen(argv[2],"r");

    if(fp1==NULL){
        printf("errore nell'apertura del file \n");
        return 1;
    }

    if(fp2==NULL){
        printf("errore nell'apertura del file \n");
        return 1;
    }

    while((fgets(c1,sizeof(c1),fp1)!=NULL))//leggo il primo file di c1 caratteri finche non è diverso da null
    {
        if((fgets(c2,sizeof(c2),fp2)==NULL))// leggo il 2 file di c2 caratteri finche no
        {
            notequal=1;
        break;
        }
        if( strcmp(c1,c2) != 0 ) //confronto fra due stringhe
        {
            notequal=1;
        break;
        }
        if(fgets(c2,sizeof(c2),fp2)!=NULL)
        {notequal=1;} //rileggo un'altra volta il secondo file  e controllo che non sia finito.. se ciò non accade vuol dire che sono diversi

        if (notequal){
            printf(" i file \"%s\" e \"%s\" sono uguali\n",argv[1],argv[2]);
            return 0;
        }

        if (!notequal){
            printf(" i file \"%s\" e \"%s\" sono diversi\n",argv[1],argv[2]);
            return 0;
        }
    }




}


//char buf[3]
//while (fgets(buf,sizeof(buf),"file")!=NULL)
//con fgets leggo il file ogni 3 caratteri finche è diverso da NULL

//confronto tra 2 stringhe
//

//char*filename=strrchr(argv[1],'\\');
//filename=filename?filename+1:argv[1]
