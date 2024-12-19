#include<stdio.h>
#include <string.h>

void find(int arr[], int size, const char* condition) {
    int found = 0;
    if (strcmp(condition, "chan") == 0)
    {
        printf("cac so chan: ");
        for (int i = 0; i < size; i++)
        {
            if (arr[i] % 2 == 0)
            {
                printf("%d ", arr[i]);
                found = 1;
            }
            
        }
    } else if (strcmp(condition, "le") == 0)
    {
        printf("cac so le: ");
        for (int i = 0; i < size; i++)
        {
            if (arr[i] % 2 != 0)
            {
                printf("%d ", arr[i]);
                found = 1;
            }
            
        }
    } else if (strcmp(condition, "lon hon") == 0)
    {
        printf("cac so lon hon 0: ");
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > 0)
            {
                printf("%d ", arr[i]);
                found = 1;
            }
        }
    }
    
    if (!found)
    {
        printf("ko co so nao thoa man dieu kien\n");
    }
}

int main() {
    int n;
    char condition[20];
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
    getchar();
    printf("nhap dieu kien tim kiem (chan/le/lon hon): ");
    fgets(condition, sizeof(condition), stdin);
    condition[strcspn(condition, "\n")] = '\0';
    find(arr, n, condition);
    return 0;
}