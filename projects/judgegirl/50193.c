#include <stdio.h>
#include <stdlib.h>

int Min(int x, int y) {
	if(x >= y) return y;
	else return x;
}

void swap(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	int a, b;
	int ah, am, as;
	int bh, bm, bs;
	int t;
	int min = 300000;
	int n;
	int s = 0;
	scanf("%d", &a);

	while(scanf("%d", &b) == 1) {
		n = b;
		if(a < b) swap(&a, &b);
		as = a % 100;
		a /= 100;
		am = a % 100;
		a /= 100;
		ah = a;
		bs = b % 100;
		b /= 100;
		bm = b % 100;
		b /= 100;
		bh = b;
		if(as < bs) {
			as += 60;
			am--;
		}
		if(am < bm) {
			am += 60;
			ah--;
		}
		t = (ah-bh)*10000 + (am-bm)*100 + (as-bs);
		min = Min(min, t);
		a = n;
	}
	s += min % 100;
	min /= 100;
	s += (min % 100) * 60;
	min /= 100;
	s += min*60*60;
	printf("%d", s);
}
