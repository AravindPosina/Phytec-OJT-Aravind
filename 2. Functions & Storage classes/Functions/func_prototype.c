#include <stdio.h>

float calculateRectangleArea(float len, float width);

int main()
{
	float len = 5.0;
	float width = 3.0;

	float area = calculateRectangleArea(len, width);

	printf("The area of the rectangle is: %.2f\n", area);

	return 0;
}

float calculateRectangleArea(float len, float width)
{
	return len * width;
}

