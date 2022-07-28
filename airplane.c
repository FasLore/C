//
//  main.c
//  17
//
//  Created by federico on 22/09/17.
//  Copyright © 2017 federico. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct modello_aereo {
    char modello[20];
    int num_passeggeri;
    enum {nazionale, internazionale, intercontinentale} tratta;
    float ali;
    int velocita;
}mod_aereo;

int main(int argc, const char * argv[]){

    if (argc <4){
        printf("uso: %s  nome_file_input,numero_passeggeri,apertura_alare\n ",argv[0]);
        return(EXIT_FAILURE);
        
    }

    FILE *faereo;
    if((faereo=fopen(argv[1],"r"))!=NULL){
        fseek(faereo,0,SEEK_END);
        long num_vol=(ftell(faereo)/sizeof(mod_aereo));
        rewind(faereo);
        mod_aereo voli[num_vol];
        fread(voli,sizeof(mod_aereo),num_vol,faereo);
        fclose(faereo);
        int num_pass=strtof(argv[2],NULL);
        float apertura_alare=strtof(argv[3],NULL);

        for(int i=0;i<num_vol;i++){
            if((voli[i].num_passeggeri > num_pass) && (voli[i].ali > apertura_alare)){
                
                printf("Modello: %s \n",voli[i].modello);
                printf("Passeggeri: %d \n",voli[i].num_passeggeri);
                printf("apertura alare: %.2f\n ",voli[i].ali);
                printf("velocità: %d km/h\n ",voli[i].velocita);
                if(voli[i].tratta==0)
                    printf("Raggio: nazionale \n");
                if(voli[i].tratta==1)
                    printf("Raggio: internazionale \n");
                if(voli[i].tratta==2)
                    printf("Raggio: intercontinetale \n");
                printf("\n");
            }
        }
    }else{
        printf("errore nell'apertura del file.\n");
        return(EXIT_FAILURE);

    }
    return 0;
}
