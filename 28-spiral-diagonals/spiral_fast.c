#include <stdio.h>
#include <math.h>

#define MAX_VAL 1001
int main(int argc, char *argv[])
{
	int i, sum= 1;
	for(i = 3; i <= MAX_VAL; i+=2)
		sum += 4*pow(i,2)-6*i +6;

	printf("%d\n", sum);
}
