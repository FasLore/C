#include <stdio.h>

int matrix(int m, int n, int v[m][n])
{
    int i=0,j=0,s=0,col;
    for (i=0;i<m;i++)
    {
        s=s+v[i][j];
        j++;
        if(j==n) j=0;
    }
    int sd=0;
    for(col=1;col<n;col++)
    {
        j=col;
        for(i=0;i<m;i++)
        {
            sd=sd+v[i][j];
            j++;
            if(j==n) j=0;
        }
        if(sd!=s) return 0;
        sd=0;
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    int v[3][3];int p;
    v[0][0]=1;
    v[0][1]=1;
    v[0][2]=1;
    v[1][0]=1;
    v[1][1]=1;
    v[1][2]=1;
    v[2][0]=1;
    v[2][1]=1;
    v[2][2]=1;
    p=matrix(3,3,v);
    if(p==0){printf("err\n");}
    else {printf("V\n");}
    return 0;
}
