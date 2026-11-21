#include <stdio.h>

int main()
{
    int n, i, j, k;
    int p[20];
    int m[20][20];
    int min, cost;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions:\n");
    for(i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for(i = 1; i <= n; i++)
        m[i][i] = 0;

    for(int l = 2; l <= n; l++)
    {
        for(i = 1; i <= n-l+1; i++)
        {
            j = i + l - 1;
            min = 999999;

            for(k = i; k < j; k++)
            {
                cost = m[i][k] + m[k+1][j]
                       + p[i-1] * p[k] * p[j];

                if(cost < min)
                    min = cost;
            }

            m[i][j] = min;
        }
    }

    printf("\nMinimum number of multiplications = %d\n", m[1][n]);

    return 0;
}