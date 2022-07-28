#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, const char * argv[])
{
    bool val=true;
    char *p;
    int i=1;
    int k=0;
    p=malloc(i*sizeof(char));
    char c;
    printf("inserisci la stringa che desideri: ");
    while((c=getchar())!= '\n')
    {
        p[i-1]=c;
        i++;
        p=realloc(p,i*sizeof(char));
    }
    p[i-1]='\0';
    int l = strlen(p);
    for(k=0;k<((l)/2);k++)
    {
        if(p[k]!= p[(l-k)-1]) {val=false;}
    }
    if (val==true)
    {printf("é palindroma \n");}
    else {printf("non è palindroma \n");}
    return 0;
}
