#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, W;
    int wt[20], val[20];
    int dp[20][50];
    int i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],
                                dp[i-1][j]);

            else
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    return 0;
}