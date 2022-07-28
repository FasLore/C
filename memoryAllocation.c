#include <stdio.h>
#include <stdlib.h>


int *alloca_vettore (int n)
{
    int *p;
    p=calloc(n, sizeof(int));
    return p;
    //return calloc(n, sizeof(int));
}

int init_vet(int v[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        v[i]=2+i; // *(v+i)=2*i
    }
    return 0;
}

int print_vettore(int v[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("v[%d]=%d \n",i,v[i]);
    }
    return 0;
}

                                                           int main(int argc, const char * argv[])
                                                            {
                                                            //leggi dimensione del vettore
                                                            int l=0,*vet,error=0;
                                                            printf("dimensione: ");
                                                            scanf(" %d", &l);
                                                            vet=alloca_vettore(l);
                                                            if(error)
                                                            {
                                                                printf("memoria insufficiente \n");
                                                                return -1;
                                                            }
                                                            error=init_vet(vet,l);
                                                            if (!error)
                                                            {
                                                             print_vettore(vet,l);
                                                            }
                                                            free(vet);
                                                             return 0;
                                                            }
