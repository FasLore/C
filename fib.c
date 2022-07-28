#include <stdio.h>
int main(int argc, const char * argv[]) {
    int n,i;
    printf("posizione: ");
    scanf("%d", &n);
    int v[n];
    if (n==1 || n==2)
    {
        v[0]=1;
        printf("%d \n", v[0]);
    }

    else
    {
        v[0]=1;
        v[1]=1;
        for (i=2;i<n;i++)
        {
            v[i]=v[i-1]+v[i-2];
        }
        printf("%d \n", v[i]);
    }
    return 0;
}
