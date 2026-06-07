#include <stdio.h>
#include <stdlib.h>

int tot = 0;

void Segment(int a1, int b1, int a2, int b2) {
    if(a1*a2 > 0) {
        if(b1*b2 > 0) {
            tot += 1;
            //printf("+1\n");
        }
        else if(b1*b2 < 0) {
            tot += 2;
            //printf("+2 (b1*b2 < 0)\n");
        }
    }
    else if(a1*a2 < 0) {
        if(b1*b2 > 0) {
            tot += 2;
            //printf("+2 (a1*a2 < 0)\n");
        }
        else if(b1*b2 < 0) {
            if(a1*b2 == a2*b1) {
                tot += 2;
                //printf("+2 (a1/b1) == (a2/b2)\n");
            }
            else {
                tot += 3;
                //printf("+3\n");
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int x, y;
    int x1, y1, x2, y2;
    scanf("%d %d", &x, &y);
    x1 = x, y1 = y;
    scanf("%d %d", &x2, &y2);
    Segment(x, y, x2, y2);
    x1 = x2;
    y1 = y2;
    for(int i = 2; i < n; i++) {
        scanf("%d %d", &x2, &y2);
        Segment(x, y, x2, y2);
        Segment(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
    }
    printf("%d\n", tot);
}