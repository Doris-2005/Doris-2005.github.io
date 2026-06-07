#include <stdio.h>
#include <stdlib.h>

int main() {
	int k;
	scanf("%d", &k);
	if(k == 0) {
		for(int i = 1; i <= 9; i++) {
			for(int j = 0; j < 4; j++) {
				printf("%d", i);
			}
			printf("\n");
		}
	}
	else {
		for(int i = 1; i <= 9; i++) {
			for(int j = (i-k > 0 ? i-k : 0); j <= 9; j++) {
				if(abs(j-i) > k) break;
				for(int l = (j-k > 0 ? j-k : 0); l <= 9; l++) {
					if(abs(l-j) > k) break;
					for(int m = (l-k > 0 ? l-k : 0); m <= 9; m++) {
						if(abs(m-l) > k) break;
						printf("%d%d%d%d\n", i, j, l, m);
					}
				}
			}
		}
	}
}
