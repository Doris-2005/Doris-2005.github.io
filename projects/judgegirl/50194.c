#include <stdio.h>
#include <stdlib.h>

int Num(int x) {
	int times = 1;
	while(x / 10 > 0) {
		times++;
		x /= 10;
	}
	return times;
}

int main() {
	int k;
	int L;
	int n;
	int c = 0;
	int t;
	int nc;
	scanf("%d", &k);
	scanf("%d", &L);
	while(scanf("%d", &n) == 1) {
		if(n == 0) break;
		t = n % k;
		nc = Num(n)*t;
		if(nc > L) continue;
		else if(c + nc > L) {
			printf("\n");
			c = nc;
			for(int i = 0; i < t; i++) printf("%d", n);
		}
		else {
			c += nc;
			for(int i = 0; i < t; i++) printf("%d", n);
		}
	}
}
