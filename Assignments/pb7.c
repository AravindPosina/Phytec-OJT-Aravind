#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int *data;
    int n, choice;
    int data_space_size = 0;

    while (1) {
        printf("Current data space size: %d bytes\n", data_space_size);
        printf("1. Allocate memory\n");
        printf("2. Free memory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size to allocate (in bytes): ");
                scanf("%d", &n);
                data = sbrk(n);

                if (data == (int *)(-1)) {
                    perror("sbrk");
                    return 1;
                }

                data_space_size += n;
                printf("Allocated %d bytes at address %p\n", n, data);
                break;

            case 2:
                if (data_space_size == 0) {
                    printf("No memory to free.\n");
                } else {
                    brk(data);
                    data_space_size = 0;
                    printf("Freed all allocated memory.\n");
                }
                break;

            case 3:
                if (data_space_size > 0) {
                    brk(data);
                }
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

