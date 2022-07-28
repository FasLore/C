#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *p;
    char t[10];
    p=fopen("/Users/federico/Desktop/tasse/fedet.rtf","r");
    if (!p)
    {
        printf("impossibile aprire il file %s in lettura \n","fedet.rtf");
        return 1;
    }
    fscanf(p,"%d",t);
    printf("%d\n",t);
    fclose(p);
    return 0;
}
