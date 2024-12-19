#include <stdio.h>

int binarySearch(int arr[], int left, int right, int search) {
    if(left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == search)
    {
        return mid;
    } else if (arr[mid] > search)
    {
        return binarySearch(arr, left, mid - 1, search);
    } else
    {
        return binarySearch(arr, mid + 1, right, search);
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
    
    printf("nhap gia tri can tim: ");
    scanf("%d", &search);
    int result = binarySearch(arr, 0, n - 1, search);
    if (result != -1)
    {
        printf("phan tu %d nam o vi tri %d\n", search, result);
    } else
    {
        printf("ko tim thay\n");
    }
    return 0;
}