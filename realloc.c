#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
 if(argc!=3)
 {
     printf("errore \n");
     return 1;
 }
    FILE *fp;
    FILE *fo;
    int i=1;
    char c;
    int *m=malloc(i*sizeof(char));
    fp=fopen(argv[1],"r");
    if(fp==NULL)
    {
        printf("errore nell'apertura del file");
        return 1;
    }
    fo=fopen(argv[2],"w");
    if(fo==NULL)
    {
        printf("impossibile aprire il file in lettura\n");
        return 1;
    }
    c=fgetc(fp);
    while (c!=EOF)
    {
        char t;
        if(c=='a')
        {
            t='a';
            char p='A';
            char s;
            s=t;
            t=p;
            p=s;
            fprintf(fo,"%c",t);
        }
        m=realloc(m,i*sizeof(char));
        m[i-1]=c;
        i++;
        c=fgetc(fp);
        fprintf(fo,"%c",c);
    }
    free(m);
    return 0;
}
