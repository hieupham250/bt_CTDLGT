#include <stdio.h>

int main() {
	int n, k;
	scanf("%d", &n);
	if(n <=0 ) {
		printf("Mang rong! Khong the tim cap so.\n");
        return 0;
	}
	int arr[n - 1];
    int sum = 0, total_sum = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int missing = total_sum - sum;
    printf("%d", missing);
    return 0;
}
