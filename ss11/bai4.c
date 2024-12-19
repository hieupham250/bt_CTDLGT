#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int score;
} Student;

void searchStudent(Student students[], int size, char targetName[]) {
    for (int i = 0; i < size; i++)
    {
        if (strcmp(students[i].name, targetName) == 0)
        {
            printf("Điem cua %s la: %d\n", students[i].name, students[i].score);
            return;
        }
    }
    printf("ko tim thay sinh vien\n");
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    if (n <= 0) {
        printf("so luong sinh vien phai lon hon 0\n");
        return 0;
    }
    Student students[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", students[i].name, &students[i].score);
        getchar();
    }
    char targetName[50];
    printf("nhap ten sinh vien can tim: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';
    searchStudent(students, n, targetName);
    return 0;
}