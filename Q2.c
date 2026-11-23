#include <stdio.h>

int main() {
    int n = 5;
    float capacity = 18;

    float weight[] = {4, 7, 5, 3, 9};
    float value[] = {24, 42, 30, 18, 45};
    float ratio[5];
    int id[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {

                float temp;

                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;

                int t = id[j];
                id[j] = id[j + 1];
                id[j + 1] = t;
            }
        }
    }

    float totalValue = 0;
    float currentWeight = 0;

    printf("Selected Parcels:\n");

    for (int i = 0; i < n; i++) {

        if (currentWeight + weight[i] <= capacity) {

            currentWeight += weight[i];
            totalValue += value[i];

            printf("Parcel %d -> Selected: 100%%\n", id[i]);

        } else {

            float remain = capacity - currentWeight;

            if (remain > 0) {

                float fraction = remain / weight[i];

                totalValue += value[i] * fraction;
                currentWeight += remain;

                printf("Parcel %d -> Selected: %.2f%%\n",
                       id[i], fraction * 100);
            }

            break;
        }
    }

    printf("\nMaximum Total Value: %.2f\n", totalValue);

    return 0;
}
