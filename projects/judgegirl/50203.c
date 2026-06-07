#include <stdio.h>
#include <stdio.h>

int arr[100005] = {0};

int Max(int x, int y, int z) {
	if(x >= y) {
		if(x >= z) return x;
		else return z;
	}
	else {
		if(y >= z) return y;
		else return z;
	}
}

int main() {
	int n;
	int a, b;
	int h;
	scanf("%d", &n);
	while(scanf("%d %d", &a, &b) != EOF) {
		if(b == 0) {
			h = Max(arr[a]-1, arr[a+1], arr[a+2]);
			arr[a] = h+2;
			arr[a+1] = h+2;
			arr[a+2] = h+1;
		}
		else if(b == 1) {
			h = Max(arr[a], arr[a+1], arr[a+2]-1);
			arr[a] = h+1;
			arr[a+1] = h+2;
			arr[a+2] = h+2;
		}
		else if(b == 2) {
			h = Max(arr[a], arr[a+1], arr[a+2]);
			arr[a] = h+1;
			arr[a+1] = h+2;
			arr[a+2] = h+1;
		}
		else if(b == 3) {
			h = Max(arr[a]-1, arr[a+1], arr[a+2]-1);
			arr[a] = h+2;
			arr[a+1] = h+2;
			arr[a+2] = h+2;
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
