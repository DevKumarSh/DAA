#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Returns 0-based index
        }
    }
    return -1; // Not found
}

int main() {
    int books[] = {102, 118, 125, 139, 146, 158, 171, 190};
    int n = sizeof(books) / sizeof(books[0]);
    int targets[] = {146, 150};

    for (int i = 0; i < 2; i++) {
        int result = linearSearch(books, n, targets[i]);
        if (result != -1) {
            printf("Book %d is available at position %d (index %d).\n", targets[i], result + 1, result);
        } else {
            printf("Book %d is unavailable.\n", targets[i]);
        }
    }

    return 0;
}