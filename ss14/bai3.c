#include<stdio.h>
#include <stdbool.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    int loopCount = 0;
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
            
        }
        loopCount++;
        if (!swapped) {
            break;
        }
    }
    printf("sap xep sau %d lan lap\n", loopCount);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("mang dau: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("mang da sap xep: ");
    printArray(arr, n);
    return 0;
}