#include <stdio.h>
#include <string.h>

void reverse_string(char str[], int start, int end);

int main() {
	char str[1000];
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	reverse_string(str, 0, strlen(str)-1);
	printf("%s", str);
	return 0;
}

void reverse_string(char str[], int start, int end) {
	if(start >= end) {
		return;
	}
	char ch = str[start];
	str[start] = str[end];
	str[end] = ch;
	reverse_string(str, start+1, end-1);
}
