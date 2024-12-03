#include<stdio.h>
#include <stdbool.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int k, arrNew[n], newSize = 0;
	scanf("%d", &k);
	for(int i = 0; i < n; i++){
		if(arr[i] != k) {
			arrNew[newSize++] = arr[i];	
		}
	}
	if(newSize == n) {
		printf("khong co phan tu %d", k);
		return 0;
	}
	for(int i = 0; i < newSize; i++){
		
		printf("%d ", arrNew[i]);
	}
	return 0;
}
