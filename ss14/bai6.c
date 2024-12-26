#include<stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void insertionSort(int arr[], int size) {
   for (int i = 0; i < size; i++)
   {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
   }
   
}

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int hight = size - 1;
    while (low <= hight)
    {
        int mid = low + (hight - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        } else if(arr[mid] > target) {
            hight = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

int main() {
    int n, select, number, result;
    int arr[n];
    do
    {
        printf("----------MENU----------\n");
        printf("1. Them phan tu\n");
        printf("2. Sap xep chen\n");
        printf("3. Tim kiem tuyen tinh\n");
        printf("4. Tim kiem nhi phan\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&select);
        switch(select){
            case 1:
                scanf("%d", &n);
                arr[n];
                for (int i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                break;
            case 2: 
                insertionSort(arr, n);
                printArray(arr, n);
                break;
            case 3:
                printf("nhap phan tu can tim: ");
                scanf("%d", &number);
                result = linearSearch(arr, n, number);
                if (result != -1)
                {
                    printf("tim thay tai vi tri: %d\n", result);
                } else {
                    printf("ko tim thay\n");
                }
                break;
            case 4:
                printf("nhap phan tu can tim: ");
                scanf("%d", &number);
                insertionSort(arr, n);
                result = binarySearch(arr, n, number);
                if (result != -1)
                {
                    printf("tim thay tai vi tri: %d\n", result);
                } else {
                    printf("ko tim thay\n");
                }
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Lua chon khong hop le");
                break;
        }
    } while (1 == 1);
    return 0;
}