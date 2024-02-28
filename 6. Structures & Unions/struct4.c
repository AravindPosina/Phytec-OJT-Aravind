#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[50];
    struct Date birthdate;
};

int main() {
    struct Person person1 = {"John Doe", {25, 12, 1990}};

    printf("Person: %s\nBirthdate: %d/%d/%d\n", person1.name, person1.birthdate.day, person1.birthdate.month, person1.birthdate.year);

    return 0;
}

