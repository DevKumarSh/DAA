#include <stdio.h>
#include <limits.h>

int main()
{
    int i, j, l, n, k;
    int p[20], dp[20][20];
    int cost;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("\n Enter dimension of matrices: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for (l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("\nMinimum Multiplication Cost = %d\n", dp[1][n]);
    return 0;
}
