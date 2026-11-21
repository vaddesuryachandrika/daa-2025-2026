
#include <stdio.h>

int cost[10][10];
int visited[10];
int n;
int mincost = 9999;

void tsp(int city, int count, int total)
{
    int i;

    if(count == n && cost[city][0] != 0)
    {
        int finalcost = total + cost[city][0];

        if(finalcost < mincost)
        {
            mincost = finalcost;
        }

        return;
    }

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0 && cost[city][i] != 0)
        {
            visited[i] = 1;

            tsp(i, count + 1, total + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[0] = 1;

    tsp(0, 1, 0);

    printf("\nMinimum travelling cost = %d", mincost);

    return 0;
}
