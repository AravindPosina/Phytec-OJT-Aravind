#include<stdio.h>
#include<string.h>
#include "struct_demo.h"
int main()
{
	emp e1,e2;
	e1.eid=12342;
	strcpy(e1.name,"saishitha");
	e1.sal=95000;
	
	e2.eid=24236;
	e2.sal=85000;
	strcpy(e2.name,"anju ");
	showemp(&e1);
	showemp(&e2);
}
