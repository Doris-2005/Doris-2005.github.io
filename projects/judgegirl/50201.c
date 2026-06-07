#include <stdio.h>
#include <stdlib.h>

int a[601][601];
int lb, rb, ub, db;
int r, c;

void Down(int x) {
	int n1 = ub+x-1;
	int n2 = ub+x;
	while(n1 >= ub) {
		for(int i = lb; i <= rb; i++) {
			a[n2][i] += a[n1][i];
		}
		n1--;
		n2++;
	}
	ub += x;
}

void Left(int x) {
	int n1 = rb-x+1;
	int n2 = rb-x;
	while(n1 <= rb) {
		for(int i = ub; i <= db; i++) {
			a[i][n2] += a[i][n1];
		}
		n1++;
		n2--;
	}
	rb -= x;
}

void Dia(int x) {
	int n1 = ub;
	int n2 = rb-x+1;
	while(n2 < rb) {
		for(int i = n1+1, j = n2+1; i < ub+x; i++, j++) {
			a[i][n2] += a[n1][j];
			a[n1][j] = 0;
		}
		n1++;
		n2++;
	}
}

int main() {
	int t, k;
	scanf("%d %d", &r, &c);
	lb = 1, rb = c, ub = 1, db = r;
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	while(scanf("%d %d", &t, &k) != EOF) {
		if(t == 1) {
			Down(k);
		}
		else if(t == 2) {
			Left(k);
		}
		else {
			Dia(k);
		}
	}
	for(int i = ub; i <= db; i++) {
		for(int j = lb; j <= rb; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
