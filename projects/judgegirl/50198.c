#include <stdio.h>
#include <stdlib.h>

int Check(int n) {
	int a[15] = {0};
	int t;
	int c = 0;
	while(n > 0) {
		t = n % 10;
		a[t]++;
		n /= 10;
	}
	for(int i = 0; i <= 9; i++) {
		if(a[i]) {
			c++;
		}
	}
	if(c > 2) return 0;
	else return 1;
}

int main() {
	int a, b, x;
	while(scanf("%d %d %d", &a, &b, &x) == 3) {
		while(1) {
			if(Check(x)) break;
			x = (a*x) % b;
		}
		printf("%d\n", x);
	}
}
