#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a[10], b[10];
		int l = 1;
		int g = 1;
		for(int j = 0; j < 4; j++) {
			scanf("%d", &a[j]);
			scanf("%d", &b[j]);
		}
		float mida = 0, midb = 0;
		for(int j = 0; j < 4; j++) {
			mida += a[j];
			midb += b[j];
		}
		mida /= 4;
		midb /= 4;

		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3-j; k++) {
				if((a[k]-mida)*(b[k+1]-midb)-(a[k+1]-mida)*(b[k]-midb) < 0) {
					swap(&a[k],&a[k+1]);
					swap(&b[k],&b[k+1]);
				}
			}
		}
		int aa, bb, cc;
		a[4] = a[0];
		b[4] = b[0];
		a[5] = a[1];
		b[5] = b[1];
		for(int j = 0; j < 4; j++) {
			aa = ((a[j]-a[j+1])*(a[j]-a[j+1]))+((b[j]-b[j+1])*(b[j]-b[j+1]));
			bb = ((a[j+1]-a[j+2])*(a[j+1]-a[j+2]))+((b[j+1]-b[j+2])*(b[j+1]-b[j+2]));
			cc = ((a[j]-a[j+2])*(a[j]-a[j+2]))+((b[j]-b[j+2])*(b[j]-b[j+2]));
			if(aa+bb != cc) {
				g=0;
			}
			if(aa != bb) {
				l=0;
			}
		}
		if(g==0&&l==0) {
			printf("other\n");
		}
		else if(g==0&&l!=0) {
			printf("diamond\n");
		}
		else if(g!=0&&l==0) {
			printf("rectangle\n");
		}
		else {
			printf("square\n");
		}
	}
	return 0;
}
