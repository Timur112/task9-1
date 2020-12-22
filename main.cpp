#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* AtoB(int **a,int n,int m)
{
    int i,j,*b;
    b=(int*) malloc(m*n*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            b[j+i*m]=a[i][j];
        }
    }
    return b;
}
int** BtoA(int *b,int n,int m)
{
    int i,j,**a;
    a=(int**) malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        a[i]=(int*) malloc(m*sizeof(int));
    }
    for(i=0;i<n*m;i++)
    {
        a[i/m][i%m]=b[i];
    }
    return a;
}
int main()
{
    int n,m,i,j,**a,*b;
    printf("¬ведите число строк массива");
    scanf("%d", &n);
    printf("¬ведите число столбцов массива");
    scanf("%d", &m);
    a=(int**) malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        a[i]=(int*) malloc(m*sizeof(int));
    }
    b=(int*) malloc(m*n*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("¬ведите значение a[%d][%d]\n", i,j);
            scanf("%d", &a[i][j]);
        }
    }
    b=AtoB(a,n,m);
    for(i=0;i<n*m;i++)
    {
        printf("b[%d]=%d,",i,b[i]);
    }
    printf("\n");
    for(i=0;i<n*m;i++)
    {
        printf("¬ведите значение b[%d]\n", i);
        scanf("%d", &b[i]);
    }
    a=BtoA(b,n,m);
    for(i=0;i<n;i++,printf("\n"))
    {
        for(j=0;j<m;j++)
        {
            printf("%4d ", a[i][j]);
        }
    }
    return 0;
}
