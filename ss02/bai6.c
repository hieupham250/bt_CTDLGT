#include<stdio.h>
#include <stdbool.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr1[n], arr2[m];
	printf("nhap phan tu mang 1:");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr1[i]);
	}
	printf("nhap phan tu mang 2:");
	for(int i = 0; i < m; i++){
		scanf("%d", &arr2[i]);
	}
	int arrNew[n+m];
	for (int i = 0; i < n + m; i++) {
		arrNew[i] = (i < n) ? arr1[i] : arr2[i - n];
    }
    printf("Mang sau khi gop la:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", arrNew[i]);
    }
	
	return 0;
}
