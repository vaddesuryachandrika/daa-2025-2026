#include<stdio.h>
int a[10][10],v[10],n;

void dfs(int x)
{
    int i;
    printf("%d ",x);
    v[x]=1;

    for(i=0;i<n;i++)
        if(a[x][i]==1 && v[i]==0)
            dfs(i);
}

int main()
{
    int i,j,s;

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter start: ");
    scanf("%d",&s);

    dfs(s);

    return 0;
}