#include <stdio.h>
#include <stdlib.h>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int tot = A+B+C;
	tot /= 2;
	printf("%d\n%d\n%d", tot-A, tot-B, tot-C);
}
