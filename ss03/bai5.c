#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end);

int main() {
	char str[1000];
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	if (isPalindrome(str, 0, strlen(str) - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}

int isPalindrome(char str[], int start, int end) {
	if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return isPalindrome(str, start + 1, end - 1);
}
