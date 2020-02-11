#include <stdio.h>

int main() {
    int n = 10;
    int arr[10] = {1, 48, 3, 25, 4, 53, 43, 99, 85, 0};
    int gap_size, temp, flag = 1;

    printf("\nUnsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("\t%d", arr[i]);
    }

    gap_size = n;

    while (flag == 1 || gap_size > 1) {
        gap_size = (gap_size + 1) / 2;
        flag = 0;
        for (int i = 0; i < (n - gap_size); i++) {
            if (arr[gap_size + i] < arr[i]) {
                temp = arr[i + gap_size];
                arr[i + gap_size] = arr[i];
                arr[i] = temp;
                flag = 0;
            }
        }
    }

    printf("\n\nSorted array: \t");
    for (int i = 0; i < n; i++) {
        printf("\t%d", arr[i]);
    }
}