//  Scrivere un programma in linguaggio C che legge da tastiera una stringa e stampa a video “Palindroma” oppure “Non palindroma” dopo aver verificato 
//  se la stringa in input è palindroma o meno.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, const char * argv[])
{
    int i=1;
    int s=0;
    char *p;
    p=malloc(i*sizeof(char));
    char c;
    printf("scrivi una frase: ");
    while((c=getchar())!='\n')
    {
        p[i-1]=c;
        i++;
        p=realloc(p,i*sizeof(char));
    }
    p[i-1]='\0';
    int len= strlen(p); //restituisce la lunghezza della stringa
    for(int k=0;k<(len/2);k++)
    {
    if(p[k]!=p[(len-k)-1])
    {s++;}
    }
    if (s!=0)
    {printf("la frase non è polindroma \n");
        return 0;
    }
    else
    {
        printf("la frase è polindroma \n");
        return 0;
    }
    
    
    
    
    
    return 0;
}
