#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int search(int[], int, int);

int main() {
    int arr[SIZE] = {1, 4, 10, 3, 2, 5, 7, 9, 8, 6};
    int size = sizeof(arr) / sizeof(int);
    int search_term, pos;
    
    printf("\nSearch term: ");
    scanf("%d", &search_term);

    pos = search(arr, size, search_term);
    if (pos != -1) {
        printf("%d found in position %d\n", search_term, pos);
        return 0;
    }

    printf("%d NOT FOUND\n", search_term);
    return 1;
}

int search(int arr[], int size, int search) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }
    
    return -1;
}