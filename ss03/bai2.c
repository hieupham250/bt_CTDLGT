#include <stdio.h>

int total(int n, int m);

int main() {
	int n, m;
	printf("nhap n va m:");
	scanf("%d %d", &n, &m);
	if(n > m) {
		printf("n phai lon hon m");
		return 0;
	}
	
	printf("%d", total(n, m));
	return 0;
}

int total(int n, int m) {
	if(n > m) {
		return 0;
	}
	return n + total(n + 1, m);
}
