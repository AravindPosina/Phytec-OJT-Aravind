#include <stdio.h>

int main() {
    int num_count;

    printf("Enter the number of elements: ");
    scanf("%d", &num_count);

    int user_numbers[num_count];

    for (int i = 0; i < num_count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &user_numbers[i]);
    }

    int result_lcm = 1;

    for (int i = 0; i < num_count; i++) {
        int x = result_lcm;
        int y = user_numbers[i];

        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }

        result_lcm = (result_lcm * user_numbers[i]) / x;
    }

    printf("The LCM of ");
    for (int i = 0; i < num_count; i++) {
        printf("%d", user_numbers[i]);
        if (i < num_count - 1) {
            printf(", ");
        }
    }
    printf(" is: %d\n", result_lcm);

    return 0;
}

