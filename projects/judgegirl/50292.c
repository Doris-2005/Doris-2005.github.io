#include <stdio.h>
#include <stdlib.h>

int main() {
	int x1, y1;
	int x2, y2;
	int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	if(x2 <= 0 && y2 <= 0) {
		q3 = (x2-x1)*(y2-y1);
	}
	else if(x2 <= 0) {
		if(y1 >= 0) {
			q2 = (x2-x1)*(y2-y1);
		}
		else {
			q2 = (x2-x1)*y2;
			q3 = (x2-x1)*(0-y1);
		}
	}
	else if(y2 <= 0) {
		if(x1 >= 0) {
			q4 = (x2-x1)*(y2-y1);
		}
		else {
			q4 = x2*(y2-y1);
			q3 = (0-x1)*(y2-y1);
		}
	}
	else {
		if(x1 < 0 && y1 < 0) {
			q1 = x2*y2;
			q2 = (0-x1)*y2;
			q3 = (0-x1)*(0-y1);
			q4 = x2*(0-y1);
		}
		else if(x1 < 0) {
			q1 = x2*(y2-y1);
			q2 = (0-x1)*(y2-y1);
		}
		else if(y1 < 0) {
			q1 = (x2-x1)*y2;
			q4 = (x2-x1)*(0-y1);
		}
		else {
			q1 = (x2-x1)*(y2-y1);
		}
	}
	printf("%d\n%d\n%d\n%d\n", q1, q2, q3, q4);
}
