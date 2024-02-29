
#include"gpio.h"

int main()
{
	gpio();
	while(1)
	{
		ledon();
		delay(500);
		ledoff();
		delay(500);
	}

}
