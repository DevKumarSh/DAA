
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity;
    int weight[50], profit[50];
    int dp[50][50];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    for(int i = 1; i <= n; i++) {
        printf("Enter weight and profit of item %d: ", i);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    // Dynamic Programming
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {

            if(i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if(weight[i] <= w) {
                dp[i][w] = max(
                    profit[i] + dp[i-1][w-weight[i]],
                    dp[i-1][w]
                );
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][capacity]);

    return 0;
}
