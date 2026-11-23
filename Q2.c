#include <stdio.h>

struct Parcel {
    int id;
    float weight;
    float value;
    float ratio;
};

int main() {
    int n = 5;
    float capacity = 18.0;
    float weights[] = {4, 7, 5, 3, 9};
    float values[] = {24, 42, 30, 18, 45};
    struct Parcel p[5];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].weight = weights[i];
        p[i].value = values[i];
        p[i].ratio = values[i] / weights[i];
    }

    // Sort parcels by value/weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].ratio < p[j + 1].ratio) {
                struct Parcel temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    float totalValue = 0.0, currentWeight = 0.0;

    printf("Selected Parcels:\n");
    for (int i = 0; i < n; i++) {
        if (currentWeight + p[i].weight <= capacity) {
            currentWeight += p[i].weight;
            totalValue += p[i].value;
            printf("Parcel %d (Weight: %.1f kg, Value: %.1f) -> Selected: 100%%\n", 
                   p[i].id, p[i].weight, p[i].value);
        } else {
            float remain = capacity - currentWeight;
            if (remain > 0) {
                float fraction = remain / p[i].weight;
                totalValue += p[i].value * fraction;
                currentWeight += remain;
                printf("Parcel %d (Weight: %.1f kg, Value: %.1f) -> Selected: %.2f%% (%.1f kg)\n", 
                       p[i].id, p[i].weight, p[i].value, fraction * 100, remain);
            }
            break;
        }
    }

    printf("\nMaximum Total Value: %.2f\n", totalValue);
    return 0;
}