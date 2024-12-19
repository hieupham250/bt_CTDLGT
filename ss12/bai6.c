#include <stdio.h>

int countOccurrences(int arr[], int size, int element) {
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

int isAlreadyPrinted(int arr[], int i) {
    for (int k = 0; k < i; k++) {
        if (arr[i] == arr[k]) {
            return 1;
        }
    }
    return 0;
}

void findDuplicateElements(int arr[], int n) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        int count = countOccurrences(arr, n, arr[i]);
        if (count > 1 && !isAlreadyPrinted(arr, i)) {
            printf("Phan tu %d lap lai %d lan\n", arr[i], count);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co Phan tu lap lai.\n");
    }
}

int main() {
    int n, search;
    scanf("%d", &n);
    if (n <= 0) {
        printf("so luong phan tu phai lon hon 0\n");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    findDuplicateElements(arr, n);
    return 0;
}