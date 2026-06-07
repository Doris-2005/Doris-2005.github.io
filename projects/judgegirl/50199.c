#include <stdio.h>
#include <stdlib.h>

int a[501][501] = {0};

void Row(int x, int y) {
	if(a[x][y] == a[x][y+1] && a[x][y] == a[x][y+2]) {
		a[x][y] = 0;
		a[x][y+1] = 0;
		a[x][y+2] = 0;
	}
}

void Col(int x, int y) {
	if(a[x][y] == a[x+1][y] && a[x][y] == a[x+2][y]) {
		a[x][y] = 0;
		a[x+1][y] = 0;
		a[x+2][y] = 0;
	}
}
/*
   1 1
   1
   1 1
     1
   1
   1 1
   1 
 1 1
*/
void Lsh(int x, int y) {
	if(a[x][y] == a[x+1][y] && a[x][y] == a[x][y+1]) {
		a[x][y] = 0;
		a[x+1][y] = 0;
		a[x][y+1] = 0;
	}
	else if(a[x][y] == a[x][y+1] && a[x][y] == a[x+1][y+1]) {
		a[x][y] = 0;
		a[x][y+1] = 0;
		a[x+1][y+1] = 0;
	}
	else if(a[x][y] == a[x+1][y] && a[x][y] == a[x+1][y+1]) {
		a[x][y] = 0;
		a[x+1][y] = 0;
		a[x+1][y+1] = 0;
	}
	else if(a[x][y] == a[x+1][y] && a[x][y] == a[x+1][y-1]) {
		a[x][y] = 0;
		a[x+1][y] = 0;
		a[x+1][y-1] = 0;
	}
}

int main() {
	int r, c;
	scanf("%d %d", &r, &c);
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			if(!a[i][j]) continue;
			else {
				Row(i, j);
				if(!a[i][j]) continue;
				Col(i, j);
				if(!a[i][j]) continue;
				Lsh(i, j);
			}
		}
	}
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
