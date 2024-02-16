#include<graphics.h>
#include<stdio.h>
int main()
{
	int gd = DETECT,gm;
	initgraph(&gd, &gm, "");
	circle(200, 250, 50);
	delay(5000);
	return 0;
}

