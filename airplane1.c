#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum _modello
{
    Boeing707,
    Boeing747,
    AirbusA380,

}modello_aereo;
typedef struct _volo
{
    char agenzia[20];
    modello_aereo modello;
    int orario_partenza;
    int orario_arrivo;
    char l_partenza[20];
    char l_destinazione[20];
}Voli;



int main(int argc, const char * argv[])
{
    if(argc < 5)
    {
        printf("uso: %s file di output,luogo di partenza, luogo di destinazione\n",argv[0]);
        return(EXIT_FAILURE);
    }
    FILE *fp;
    if((fp=fopen(argv[1],"rb"))!=NULL)
    {
        FILE *fo;
        if((fo=fopen(argv[2],"w"))!=NULL)
        {
            fseek(fp,0,SEEK_END);
            long num_vol=(ftell(fp)/sizeof(Voli)); // ftell ti dice la position di dove si trova il puntatore
            rewind(fp);
            Voli voli[num_vol];
            fread(voli,sizeof(Voli),num_vol,fp);
            fclose(fp);
        
            for(int i=0;i<num_vol;i++)
            {
                char lp[30];
                sprintf(lp,"%s",voli[i].l_partenza);
                char ld[30];
                sprintf(ld,"%s",voli[i].l_destinazione);
                if(!strcmp(lp,argv[3]))
                    if(!strcmp(ld,argv[4]))
                    {
                        fprintf(fo,"agenzia e modello aereo: %s %u\n",voli[i].agenzia,voli[i].modello);
                        fprintf(fo,"luogo di partenza %s e luogo d'arrivo %s",voli[i].l_partenza,voli[i].l_destinazione);;
                        fprintf(fo,"orario di partenza: %d",voli[i].orario_arrivo);
                        fprintf(fo,"orario d'arrivo: %d",voli[i].orario_arrivo);
                        fprintf(fo,"\n");
                    }
            }
            fclose(fo);
        }
        else
        {
            printf("errore nell'apertura del file.\n");
            return(EXIT_FAILURE);
        }
    }
    else
    {
        printf("errore nell'apertura del file.\n");
        return(EXIT_FAILURE);
    }
return 0;
}
