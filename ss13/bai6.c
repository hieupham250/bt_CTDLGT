#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size) {
    int loopCount = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i) {
            swap(&arr[min], &arr[i]);
            loopCount++; 
            printf("Hoán đổi: ");
            for (int k = 0; k < size; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
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
    printf("mang ban dau: ");
    printArray(arr, n);
    printf("\n");
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}