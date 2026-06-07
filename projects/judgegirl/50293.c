#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int c, minc;

int Min(int a, int b) {
	if(a >= b) return b;
	else return a;
}
int Max(int a, int b) {
	if(a > b) return a;
	else if(a < b) {
		minc = c;
		return b;
	}
	else {
		if(c > minc) return a;
		else {
			minc = c;
			return a;
		}
	}
}

int main() {
	int n;
	int ty;
	int f;
	int l;
	int p;
	int maxp;
	int fp;
	int fc;
	bool b = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &ty);
		if(i == 0) {
			f = ty;
			l = ty;
			p = ty;
			maxp = ty;
			c = ty;
			minc = ty;
			fp = ty;
			fc = ty;
		}
		else {
			if(b && ty != l) {
				b = 0;
				fp = p;
				fc = c;
			}
			if(b) {
				if(i == n-1) {
					if(ty == l) {
						p += ty;
						maxp = p;
					}
					else {
						maxp = Max(maxp, p);
						l = ty;
						c = ty;
						if(ty == f) {
							fp += ty;
							maxp = Max(maxp, fp);
						}
					}
				}
				else {
					if(ty == l) {
						p += ty;
					}
					else {
						maxp = Max(maxp, p);
						l = ty;
						c = ty;
						p = ty;
					}
				}
			}
			else {
				if(i == n-1) {
					if(ty == l) {
						p += ty;
						if(ty == f) {
							p += fp;
							maxp = Max(maxp, p);
						}
					}
					else {
						maxp = Max(maxp, p);
						l = ty;
						c = ty;
						if(ty == f) {
							fp += ty;
							maxp = Max(maxp, p);
						}
					}
				}
				else {
					if(ty == l) {
						p += ty;
					}
					else {
						maxp = Max(maxp, p);
						l = ty;
						c = ty;
						p = ty;
					}
				}
			}
		}
	}
	printf("%d %d", minc, maxp/minc);
}
