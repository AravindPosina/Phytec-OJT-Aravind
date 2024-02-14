#include <stdio.h>
int main() 
{
    int seconds, hours, minutes;
    printf("Enter the number of seconds: ");
    scanf("%d", &seconds);
    hours = seconds / 3600;  // 1 hour = 3600 seconds
    seconds %= 3600;
    minutes = seconds / 60;  // 1 minute = 60 seconds
    seconds %= 60;
    printf("Converted time: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    return 0;
}

