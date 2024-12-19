#include<stdio.h>

void checkSymmetry(int arr[], int size) {
    int check = 0;
    for (int i = 0; i < size / 2; i++)
    {
        if(arr[i] == arr[size - i - 1]) {
        printf("cap doi xung: (%d, %d)\n", arr[i], arr[size - i - 1]);
        check = 1;
        }
    }
    if(!check) {
        printf("ko co mang doi xung\n");
    }
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
    checkSymmetry(arr, n);
    return 0;
}