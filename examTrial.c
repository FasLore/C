#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_res(int rows, int cols, int *m){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%2d ", m[i*cols+j]);
        }
        printf("\n");
    }
    printf("\n");
}


int extract_diagonal(int *m,int rig,int col,int d,int *m_ris){
    int s=(d-1)/2;
    int r=0;
    for (int i=s;i>=0;i--){
        for(int j=i;j<col;j++){
            m_ris[r*col+j]=m[(j-i)*col+j];
        }
        r++;
    }
    for (int i=s;i>0;i--){
        for(int j=0;j<col-s;j++){
            m_ris[r*col+j]=m[(j+i)*col+j];
        }
        r++;
    }
return 0;
}

int main(int argc, const char * argv[]){
    FILE *fmat;
    if(argc!=3){
        printf("errore \n");
        return (EXIT_FAILURE);
    }
    if((fmat=fopen(argv[1],"rb"))!=NULL){
        int dim_mat[2];
        fread(dim_mat,sizeof(int),2,fmat);
        int rig=dim_mat[0];
        int col=dim_mat[1];
        int matrix[rig][col];
        fread(matrix, sizeof(int), rig*col,fmat);
        fclose(fmat);
        print_res(rig,col,(int*)matrix);
        
        int d=(int)strtol(argv[2],NULL,10);
        //Esegue l'analisi della stringa C stringa che interpreta il suo contenuto come un numero
        // integrale della base specificata, che viene restituito come un valore int lungo.
        // Se endptr non è un puntatore nullo, la funzione imposta anche il valore di endptr per
        // puntare al primo carattere dopo il numero.
        if(!((d%2!=0)&&(d<2*rig))){
            printf("errore \n");
            return (EXIT_FAILURE);
        }
        int m_ris[d][col];
        memset(m_ris,0,d*col*sizeof(int));
        extract_diagonal((int*)matrix,rig,col,d,(int*)m_ris);
        print_res(d,col,(int*)m_ris);
        
        
    }else{
        printf("errore nell'apertura del file\n");
        return (EXIT_FAILURE);
    }


    
    
    
    return 0;
}
