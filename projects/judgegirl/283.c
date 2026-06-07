#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x, y, z;
	z = a-c;
	y = (b-8*a+6*c)/2;
	x = a-y-z;
	printf("%d\n%d\n%d\n", x, y, z);

	return 0;
}
