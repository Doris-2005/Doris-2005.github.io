#include <stdio.h>
#include <stdlib.h>

int a[501][501] = {0};
int h, w;

void Row1(int x, int y) {
	if(x-1 >= 0) {
		if(a[x-1][y] != 1) {
			a[x-1][y] = 1;
			Row1(x-1, y);
		}
	}
}

void Dia1(int x, int y) {
	if(x-1 >= 0 && y+1 < w) {
		if(a[x-1][y+1] != 1) {
			a[x-1][y+1] = 1;
			Dia1(x-1, y+1);
		}
	}
}

void Col1(int x, int y) {
	if(y+1 < w) {
		if(a[x][y+1] != 1) {
			a[x][y+1] = 1;
			Col1(x, y+1);
		}
	}
}

void Dia2(int x, int y) {
	if(x+1 < h && y+1 < w) {
		if(a[x+1][y+1] != 1) {
			a[x+1][y+1] = 1;
			Dia2(x+1, y+1);
		}
	}
}

void Row2(int x, int y) {
	if(x+1 < h) {
		if(a[x+1][y] != 1) {
			a[x+1][y] = 1;
			Row2(x+1, y);
		}
	}
}

void Dia3(int x, int y) {
	if(x+1 < h && y-1 >= 0) {
		if(a[x+1][y-1] != 1) {
			a[x+1][y-1] = 1;
			Dia3(x+1, y-1);
		}
	}
}

void Col2(int x, int y) {
	if(y-1 >= 0) {
		if(a[x][y-1] != 1) {
			a[x][y-1] = 1;
			Col2(x, y-1);
		}
	}
}

void Dia4(int x, int y) {
	if(x-1 >= 0 && y-1 >= 0) {
		if(a[x-1][y-1] != 1) {
			a[x-1][y-1] = 1;
			Dia4(x-1, y-1);
		}
	}
}

int main() {
	scanf("%d %d", &h, &w);
	int r, c, t;
	while(scanf("%d %d %d", &t, &c, &r) != EOF) {
		if(t == 0) {
			a[r][c] = 1;
		}
		else if(t == 1) {
			Row1(r, c);
			Dia1(r, c);
			Col1(r, c);
			Dia2(r, c);
			Row2(r, c);
			Dia3(r, c);
			Col2(r, c);
			Dia4(r, c);
			a[r][c] = 1;
		}
		else if(t == 2) {
			Dia1(r, c);
			Dia2(r, c);
			Dia3(r, c);
			Dia4(r, c);
			a[r][c] = 1;
		}
		else {
			Row1(r, c);
			Col1(r, c);
			Row2(r, c);
			Col2(r, c);
			a[r][c] = 1;
		}
	}
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
