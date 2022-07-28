#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,r;
    char cnt = 'y';
    printf("inserisci numero: ");
    while (cnt == 'y')
    {
        do
         {
          r=scanf("%d", &a);
            if (!r)
             {
            scanf("%*[^\n]");
            printf("il valore inserito non è un numero");
             }
        else {printf("bravo \n");}
         }
        while (!r);
        printf("Vuoi continuare? [y/n] \n");
        scanf("\n%c",&cnt); // c'è un errore dopo la prima volta non funziona più
    }
    return 0;
}
