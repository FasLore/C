#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]){

   if(argc!=3){
       printf("errore. \n");
       return 1;

   }

    FILE *fp;
    if((fp=fopen(argv[1],"rb"))!=NULL){
           long dim,n_comp;
           fseek(fp,0,SEEK_END); //punto il puntatore alla fine del file
           dim=ftell(fp); // leggo il file e stabilisco la sua dimensione
           rewind(fp); //= fseek(fp,0,SEEK_SET);
           n_comp=dim/(sizeof(float)); //dim/'float' mi dice quanti n_compl ho
           float vet[n_comp]; //float num;
           fread(vet,sizeof(float),n_comp,fp); //inserisco nell'array il num_compl letto dal file // fread(&num,sizeof(),1,fp)
           
           FILE *op;
           if((op=fopen(argv[2],"w"))!=NULL){
               int i;
               float modulo;

               for(i=2;i<n_comp+2;i=i+2){
                   modulo=sqrt(vet[i-2]*vet[i-2]+vet[i-1]*vet[i-1]); //sqrt(a^2+b^2)
                   fprintf(op,"%.3f %.3f %.3f\n",vet[i-2],vet[i-1],modulo);

               }
               fclose(fp);
               fclose(op);

           }else{
               printf("errore nell'apertura del file \n");
               return 1;

           }

       }else{
        printf("errore nell'apertura del file \n");
        return 1;

    }
    return 0;

}
