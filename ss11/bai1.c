#include<stdio.h>

void findMax(int arr[], int size) {
    int max = arr[0];
    for(int i = 0; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("%d", max);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("ko co phan tu lon nhat\n");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    findMax(arr, n);
    return 0;
}