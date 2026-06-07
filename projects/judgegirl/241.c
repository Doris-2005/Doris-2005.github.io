#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c, d, e, f, g, h;
	scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
	int ans = 1;
	if(a*d-b*c < 0) ans = 0;
	if(c*f-e*d < 0) ans = 0;
	if(e*h-g*f < 0) ans = 0;
	if(g*b-a*h < 0) ans = 0;
	printf("%d", ans);

	return 0;
}
