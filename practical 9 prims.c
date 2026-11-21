
#include <stdio.h>

int main()
{
    int cost[10][10];
    int visited[10] = {0};
    int n, i, j;
    int min, a, b;
    int edges = 0;
    int total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1)
    {
        min = 999;

        for(i = 0; i < n; i++)
        {
            if(visited[i] == 1)
            {
                for(j = 0; j < n; j++)
                {
                    if(visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", a, b, min);

        total = total + min;
        visited[b] = 1;
        edges++;
    }

    printf("\nMinimum Cost = %d", total);

    return 0;
}
