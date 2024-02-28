#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student students[3];

    // Populate the array
    for (int i = 0; i < 3; ++i) {
        printf("Enter student #%d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    // Display the array
    printf("\nStudent Details:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }

    return 0;
}

