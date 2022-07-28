#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char c1[120],c2[120];
int notequal=0;
fp1=fopen(argv[1],"r");
if
fp2=fopen(argv[2],"r");
if

while((fgets(c1,sizeof(c1),fp1)!=NULL))//leggo il primo file di c1 caratteri finche non è diverso da null
{
    if((fgets(c2,sizeof(c2),fp2)==NULL))// leggo il 2 file di c2 caratteri
    {
        notequal=1;
        break;
    }
    if( strcmp(c1,c2) != 0 ) //confronto fra due stringhe (se strcmp() == 0  vuol dire che sono uguali) 
    {
        notequal=1;
        break;
    }
    if(fgets(c2,sizeof(c2),fp2)!=NULL)
    {notequal=1;} //rileggo un'altra volta il secondo file e controllo che non sia finito.. se ciò non accade vuol dire che sono diversi
    if (notequal)
    {
        printf(" i file \"%s\" e \"%s\" sono uguali\n",argv[1],argv[2]);
        return 0;
    }
    if (!notequal)
    {
        printf(" i file \"%s\" e \"%s\" sono diversi\n",argv[1],argv[2]);
        return 0;
    }
    
}
