
#include <stdio.h>

int main() {
    int i, j, n;
    float capacity, profit[50], weight[50];
    float ratio[50], temp, totalProfit = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity: ");
    scanf("%f", &capacity);

    for(i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);

        ratio[i] = profit[i] / weight[i];
    }

    // Sorting according to ratio
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(ratio[i] < ratio[j]) {

                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    // Fractional Knapsack
    for(i = 0; i < n; i++) {
        if(weight[i] <= capacity) {
            totalProfit = totalProfit + profit[i];
            capacity = capacity - weight[i];
        }
        else {
            totalProfit = totalProfit + ratio[i] * capacity;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
