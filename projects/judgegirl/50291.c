#include <stdio.h>
#include <stdlib.h>

int tot;

void seg(int a1, int b1, int a2, int b2) {
	if(a1 * a2 < 0) {
		if(b1 * b2 < 0) {
			if(b1*a2 == b2*a1) {
				tot += 2;
			}
			else tot += 3;
		}
		else tot += 2;
	}
	else {
		if(b1 * b2 < 0) tot += 2;
		else tot += 1;
	}
}

int main() {
	int x1, x2, x3;
	int y1, y2, y3;
	for(int i = 0; i < 2; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
		tot = 0;
		seg(x1, y1, x2, y2);
		seg(x3, y3, x2, y2);
		seg(x1, y1, x3, y3);
		printf("%d\n", tot);
	}
}
