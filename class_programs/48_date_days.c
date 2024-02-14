#include <stdio.h>

int main() {
    int day1, month1, year1;
    int day2, month2, year2;

   
    printf("Enter the first date (DD MM YYYY): ");
    scanf("%d %d %d", &day1, &month1, &year1);
    printf("Enter the second date (DD MM YYYY): ");
    scanf("%d %d %d", &day2, &month2, &year2);
    int daysBetween = 0;
    daysBetween += (year2 - year1) * 360;
    daysBetween += (month2 - month1) * 30;
    daysBetween += (day2 - day1);
    printf("Number of days between the two dates: %d days\n", daysBetween);

    return 0;
}
