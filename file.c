#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    if(argc!=3)
    {
        printf("errore. \n");
        return 1;
    }
    FILE *fp;
    if((fp=fopen(argv[1],"rb"))!=NULL)
    {
      
       
        
        FILE *op;
        if((op=fopen(argv[2],"w"))!=NULL)
        {
            float num_real,num_img;
            float modulo;
            
            while(!feof(fp))//ritorna 1 se sai arrivato alla fine del file binari e test
            {
                
              size_t res= fread(&num_real,sizeof(float),1,fp);
                if(res!=1)
                {break;}
               res= fread(&num_img,sizeof(float),1,fp);
                if(res !=1)
                {break;}
                modulo=sqrt(num_real*num_real+num_img*num_img); //sqrt(a^2+b^2)
                fprintf(op,"%.3f %.3f %.3f\n",num_real,num_img,modulo);

            }
            
            fclose(fp);
            fclose(op);
        }
        else
        {
            printf("errore nell'apertura del file \n");
            return 1;
        }
    }
    else
    {
        printf("errore nell'apertura del file \n");
        return 1;
    }
    return 0;
}
