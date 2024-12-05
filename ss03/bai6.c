#include <stdio.h>

int total(int arr[], int n);

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d", total(arr, n));
}

int total(int arr[], int n) {
	if(n == 0) {
		return 0;
	}
	printf("arr[%d] = %d\n", n - 1, arr[n - 1]);
	return arr[n-1] + total(arr, n-1);
}
