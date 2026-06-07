#include <stdio.h>
#include <stdlib.h>

int main() {
	int L, W, l, w;
	scanf("%d %d %d %d", &L, &W, &l, &w);
	int maxl, maxw;
	maxl = L / l;
	maxw = W / w;
	int un;
	un = L*W - l*w*maxl*maxw;
	printf("%d\n%d", maxl*maxw, un);
}
