#include <stdio.h>

struct Size {
    int width;
    int height;
};

union Shape {
    struct Size size;
    float radius;
};

int main() {
    union Shape shape;
    shape.size.width = 10;
    shape.size.height = 5;

    printf("Rectangle Size: %dx%d\n", shape.size.width, shape.size.height);

    shape.radius = 7.5;
    printf("Circle Radius: %.2f\n", shape.radius);

    return 0;
}

