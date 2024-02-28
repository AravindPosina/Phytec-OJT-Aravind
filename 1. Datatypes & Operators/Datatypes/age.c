#include <stdio.h>

int main() {
    int birth_year, birth_month, birth_day;
    int current_year, current_month, current_day;
    int age;

    printf("Enter your date of birth (YYYY MM DD): ");
    scanf("%d %d %d", &birth_year, &birth_month, &birth_day);

    printf("Enter the current date (YYYY MM DD): ");
    scanf("%d %d %d", &current_year, &current_month, &current_day);

    age = current_year - birth_year;

    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
        age--;
    }

    printf("Your age is: %d years\n", age);

    return 0;
}
