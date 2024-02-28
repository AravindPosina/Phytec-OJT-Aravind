#include <stdio.h>

struct Rectangle {
    int length;
    int width;
};

int calculateArea(struct Rectangle rect) {
    return rect.length * rect.width;
}

int main() {
    struct Rectangle myRect = {5, 10};
    int area = calculateArea(myRect);

    printf("Rectangle Area: %d\n", area);

    return 0;
}

