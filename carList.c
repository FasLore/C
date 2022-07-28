#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum _alimentazioni{
    disel,
    benzina,
    ibrida,
    metano,
    gpl,
    
}TipoAlimentazione;

typedef struct _car{
    char marca[20];
    char modello[20];
    TipoAlimentazione alimentazione;
    int cilindrata;
    float consumo_medio;
    
}Car;

void ali2str(char *str,TipoAlimentazione al){
    switch (al){
        case disel:
            sprintf(str, "disel");
            break;
        case benzina:
            sprintf(str, "benzina");
            break;
        case ibrida:
            sprintf(str, "ibrida");
            break;
        case metano:
            sprintf(str, "metano");
            break;
        case gpl:
            sprintf(str, "gpl");
            break;
            
        default:
            break;

    }
}




int main(int argc, const char * argv[]){
    if (argc <5){
        printf("uso: %s  nome_file_input,nome_file_output,alimentazione,consumo_medio",argv[0]);
        return(EXIT_FAILURE);
    
    }
    FILE *fcars;
    if((fcars=fopen(argv[1],"r"))!=NULL){
        int num_car;
        fread(&num_car,sizeof(int),1,fcars);
        Car cars[num_car];
        fread(cars,sizeof(Car),num_car,fcars);
        fclose(fcars);
        float soglia_consumo=strtof(argv[4],NULL); //interpreta la stringa argv[3] come un numero in float, se non ci fosse null il tale spazio il puntatore endptr punta al primo carattere dopo il numero.
        
    // verifico che cio che mi passa da linea di comando argv[2](tipo di alimentazione
        for(int j=0;j<num_car;j++)
        {

            char alim[20]; //20 è arbitrario
            ali2str(alim,cars[j].alimentazione);
            if(!strcmp(alim,argv[3]))
                if(cars[j].consumo_medio >=soglia_consumo)
                {
                    printf("marca e modello: %s %s \n",cars[j].marca,cars[j].modello);
                    printf("alimentazione: %s \n",alim);
                    printf("cilindrata: %d \n",cars[j].cilindrata);
                    printf("consumo medio: %.2f km/l\n\n",cars[j].consumo_medio);
                }
        }
        FILE *fo;
        if((fo=fopen(argv[2],"w"))!=NULL)
        {

                for(int j=0;j<num_car;j++)
                {
                    fprintf(fo,"marca e modello: %s %s \n",cars[j].marca,cars[j].modello);
                    fprintf(fo,"alimentazione: %u \n",cars[j].alimentazione);
                    fprintf(fo,"cilindrata: %d \n",cars[j].cilindrata);
                    fprintf(fo,"consumo medio: %.2f km/l\n\n",cars[j].consumo_medio);
                }
            }
            else
              {
                  printf("errore nell'apertura del file\n");
                  return (EXIT_FAILURE);
              }
              fclose(fo);

    }
    else
    {
        printf("errore nell'apertura del file\n");
        return (EXIT_FAILURE);
    }
    
    
    return 0;
}
