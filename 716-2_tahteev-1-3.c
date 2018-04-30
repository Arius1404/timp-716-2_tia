#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
	printf("введите 2 числа через пробел:\n");
	float x, y,res;
	scanf("%f", &x);
	scanf("%f", &y);
	res=powf(x,y);
	printf("res = %1.5f\n", res);

return 0;
}
