#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(long long x, long long y) {
	if(x == 0) return y;
	if(y == 0) return x;
	long long xx, yy;
	long long tmp;
	if(x >= y) {
		xx = x;
		yy = y;
	}
	else {
		xx = y;
		yy = x;
	}
	while(yy > 0) {
		tmp = yy;
		yy = xx % yy;
		xx = tmp;
	}
	return xx;
};

int main() {
	int n;
	long long a[300];
	long long b[300];
	long long c[300];
	long long pa[20][20];
	long long pb[20][20];
	scanf("%d", &n);
	for(int i = 1; i <= n*(n+1)/2; i++) {
		scanf("%lld", &a[i]);
		scanf("%lld", &b[i]);
		c[i] = a[i]+b[i];
	}
	for(int i = 0; i <= n+1; i++) {
		for(int j = 0; j <= n+1; j++) {
			pa[i][j] = 0;
			pb[i][j] = 0;
		}
	}
	pa[1][1] = 1;
	pb[1][1] = 1;
	long long paa = 0;
	long long pbb = 0;
	int t = 1;
	long long g;
	for(int i = 2; i <= n+1; i++) {
		for(int j = 1; j < i; j++) {
			if(pb[i][j] == 0) {
				pa[i][j] = pa[i-1][j]*a[t];
				pb[i][j] = pb[i-1][j]*c[t];
			}
			else {
				paa = pa[i-1][j] * a[t];
				pbb = pb[i-1][j] * c[t];
				if(paa == 0) pbb = 1;
				else {
					g = gcd(paa, pbb);
					paa /= g;
					pbb /= g;
				}
				pa[i][j] = pa[i][j]*pbb + paa*pb[i][j];
				pb[i][j] = pb[i][j] * pbb;	
			}
			if(pa[i][j] == 0) pb[i][j] = 1;
			else {
				g = gcd(pa[i][j], pb[i][j]);
				pa[i][j] /= g;
				pb[i][j] /= g;
			}
			
			pa[i][j+1] = pa[i-1][j]*b[t];
			pb[i][j+1] = pb[i-1][j]*c[t];
			if(pa[i][j+1] == 0) pb[i][j+1] = 1;
			else {
				g = gcd(pa[i][j+1], pb[i][j+1]);
				pa[i][j+1] /= g;
				pb[i][j+1] /= g;
			}
			t++;
		}
	}
	for(int i = 1; i <= n+1; i++) {
		printf("%lld", pa[n+1][i]);
		printf("/");
		printf("%lld", pb[n+1][i]);
		printf("\n");
	}
}
