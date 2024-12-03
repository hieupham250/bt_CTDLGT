#include <stdio.h>

int main() {
	int n, k;
	scanf("%d", &n);
	if(n <=0 ) {
		printf("Mang rong! Khong the tim cap so.\n");
        return 0;
	}
	int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("k= ");
    scanf("%d", &k);
    findPairs(arr, n, k);
    return 0;
}

void findPairs(int arr[], int n, int k){
	int found = 0;
	for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                printf("%d, %d\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }
     if (!found) {
        printf("Khong co cap so nao co tong bang %d\n", k);
    }
}
