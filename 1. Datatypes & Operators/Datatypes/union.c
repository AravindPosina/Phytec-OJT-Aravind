#include <stdio.h>
union Data {
    int i;
    float f;
    char str[20];
};
int main() {
    union Data data;
    printf("Enter data (int, float, or string): ");
    char dataType;
    scanf(" %c", &dataType);
    switch (dataType) {
        case 'i':
            printf("Enter an integer: ");
            scanf("%d", &data.i);
            printf("Integer entered: %d\n", data.i);
            break;
        case 'f':
            printf("Enter a float: ");
            scanf("%f", &data.f);
            printf("Float entered: %.2f\n", data.f);
            break;
        case 's':
            printf("Enter a string: ");
            scanf("%s", data.str);
            printf("String entered: %s\n", data.str);
            break;
        default:
            printf("Invalid data type.\n");
    }

    return 0;
}

