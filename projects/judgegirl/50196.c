#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int a = 0, b = 0;
	int now = 0;
	while(scanf("%d", &n) == 1) {
		if(n == 0) {
			if(b) {
				b *= now;
				if(a) {
					a += b;
				}
				else {
					a = b;
				}
			}
			else {
				a += now;
			}
			printf("%d", a);
			break;
		}
		else if(n == 8) {
			if(b) {
				b *= now;
				if(a) {
					a += b;
					b = 0;
				}
				else {
					a = b;
					b = 0;
				}
				now = 0;
			}
			else if(a){
				a += now;
				now = 0;
			}
			else {
				a = now;
				now = 0;
			}
		}
		else if(n == 9) {
			if(b) {
				b *= now;
				now = 0;
			}
			else {
				b = now;
				now = 0;
			}	
		}
		else {
			now *= 10;
			now += n;
		}
	}
}
