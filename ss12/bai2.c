#include<stdio.h>

void findMax(int arr[], int size) {
    int min = arr[0];
    for(int i = 0; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    printf("%d", min);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("ko co phan tu nho nhat\n");
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