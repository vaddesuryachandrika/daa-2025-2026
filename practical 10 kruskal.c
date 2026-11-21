
#include <stdio.h>

int parent[10];

int find(int i)
{
    while(parent[i] != i)
    {
        i = parent[i];
    }

    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    int cost[10][10];
    int n, i, j;
    int min, a, b;
    int u, v;
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

    // Initialize parent array
    for(i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1)
    {
        min = 999;

        // Find minimum cost edge
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        u = find(a);
        v = find(b);

        // Check cycle
        if(u != v)
        {
            printf("%d - %d = %d\n", a, b, min);

            total = total + min;
            unionSet(u, v);
            edges++;
        }

        // Remove selected edge
        cost[a][b] = 999;
        cost[b][a] = 999;
    }

    printf("\nMinimum Cost = %d", total);

    return 0;
}
