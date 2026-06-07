#include <stdio.h>
#include <stdlib.h>

int a[201][201];
int k;

int Max(int x, int y) {
	if(x >= y) return x;
	else return y;
}

int Sum(int x, int y) {
	int t = 0;
	for(int i = 0; i < k-1; i++) {
		t += a[x][y];
		x++;
		y++;
	}
	for(int i = 0; i < k-1; i++) {
		t += a[x][y];
		x++;
		y--;
	}
	for(int i = 0; i < k-1; i++) {
		t += a[x][y];
		x--;
		y--;
	}
	for(int i = 0; i < k-1; i++) {
		t += a[x][y];
		x--;
		y++;
	}
	return t;
}

int main() {
	int h, w;
	int max = 0;
	scanf("%d %d %d", &h, &w, &k);
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= h-k*2+2; i++) {
		for(int j = k; j <= w-k+1; j++) {
			max = Max(max, Sum(i, j));
		}
	}
	printf("%d", max);
}
