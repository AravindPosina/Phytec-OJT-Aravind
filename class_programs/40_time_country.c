#include <stdio.h>

int main() {
    int hrs, mins, secs;
    int newYorkHrs, newYorkMins, newYorkSecs;
    int londonHrs, londonMins, londonSecs;
    int newYorkOffset = -5; 
    int londonOffset = 0;   

    
    printf("Enter the time in Indian format (HH MM SS): ");
    scanf("%d %d %d", &hrs, &mins, &secs);

    
    int newYorkTotalSecs = (hrs * 3600) + (mins * 60) + secs + newYorkOffset * 3600;

    
    while (newYorkTotalSecs < 0) {
        newYorkTotalSecs += 24 * 3600; 
    }

    newYorkHrs = (newYorkTotalSecs / 3600) % 24;
    newYorkMins = (newYorkTotalSecs % 3600) / 60;
    newYorkSecs = newYorkTotalSecs % 60;

   
    int londonTotalSecs = (hrs * 3600) + (mins * 60) + secs + londonOffset * 3600;

    
    while (londonTotalSecs < 0) {
        londonTotalSecs += 24 * 3600; 
    }

    londonHrs = (londonTotalSecs / 3600) % 24;
    londonMins = (londonTotalSecs % 3600) / 60;
    londonSecs = londonTotalSecs % 60;

   
    printf("Indian Time: %02d:%02d:%02d\n", hrs, mins, secs);
    printf("New York Time: %02d:%02d:%02d\n", newYorkHrs, newYorkMins, newYorkSecs);
    printf("London Time: %02d:%02d:%02d\n", londonHrs, londonMins, londonSecs);

    return 0;
}

