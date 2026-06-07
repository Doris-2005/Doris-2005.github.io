#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;
	int ans=1;
	scanf("%d%d%d", &a, &b, &c);
	if(a+b <= c) ans = 0;
	if(a+c <= b) ans = 0;
	if(b+c <= a) ans = 0;
	printf("%d", ans);

	return 0;
}
