#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	int a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	int bb, cc;
	int d;
	float mid1, mid2;
	int dd, e, f;
	int arr[5];
	if(c == 0) {
		if(b == 0) {
			arr[0] = 0;
			arr[1] = 0;
			arr[2] = a;
		}
		else {
			bb = a;
			cc = b;
			d = bb*bb-4*cc;
			mid1 = (sqrt(d)-bb)/2;
			mid2 = (0-sqrt(d)-bb)/2;				
			e = -mid1;			
			f = -mid2;
			arr[0] = e;
			arr[1] = f;
			arr[2] = 0;
		}
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < 2-j; k++) {
				if(arr[k] > arr[k+1]) swap(&arr[k], &arr[k+1]);
			}
		}
		printf("%d", arr[0]);
		printf(" ");
		printf("%d", arr[1]);
		printf(" ");
		printf("%d", arr[2]);
	}
	else {
		for(int i = -1-sqrt(abs(c)); i <= sqrt(abs(c))+1; i++) {
			if(i == 0) continue;
			else if(c % i == 0) {
				//printf("%d\n", i);
				bb = a+i;
				cc = b+i*a+i*i;
				d = bb*bb-4*cc;
				if(d < 0) continue;
				//printf("k ");
				//printf("%f\n", sqrt(d));
				if(sqrt(d) != (int)sqrt(d)) continue;
				//printf("h\n");
				mid1 = (sqrt(d)-bb)/2;
				mid2 = (0-sqrt(d)-bb)/2;
				//printf("%f\n", mid1);
				//printf("%f\n", mid2);
				if(mid1 != (int)mid1|| mid2 != (int)mid2) continue;
				else {
					e = -mid1;
					f = -mid2;
					dd = -i;
					arr[0] = e;
					arr[1] = f;
					arr[2] = dd;
					for(int j = 0; j < 2; j++) {
						for(int k = 0; k < 2-j; k++) {
							if(arr[k] > arr[k+1]) swap(&arr[k], &arr[k+1]);
						}
					}
					printf("%d", arr[0]);
					printf(" ");
					printf("%d", arr[1]);
					printf(" ");
					printf("%d", arr[2]);
					break;
				}
			}
		}
	}
	return 0;
}
