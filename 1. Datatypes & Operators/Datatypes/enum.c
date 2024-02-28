#include <stdio.h>
enum Weekday {
    Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};
int main() {
    int n;
    printf("Enter the day number (1-7): ");
    scanf("%d", &n);
    if (n >= Sunday && n <= Saturday) {
        enum Weekday day = n;
        printf("The corresponding weekday is ");
        switch (day) {
            case Sunday: printf("Sunday\n"); break;
            case Monday: printf("Monday\n"); break;
            case Tuesday: printf("Tuesday\n"); break;
            case Wednesday: printf("Wednesday\n"); break;
            case Thursday: printf("Thursday\n"); break;
            case Friday: printf("Friday\n"); break;
            case Saturday: printf("Saturday\n"); break;
        }
    } else {
        printf("Invalid day number!\n");
    }
    return 0;
}

