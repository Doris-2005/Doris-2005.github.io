#include <stdio.h>
#include <stdlib.h>

int q1(int a1, int b1, int a2, int b2) {
    int l, h;    
    if(a2 <= 0) return 0;
    else if(b2 <= 0) return 0;
    else {
        if(a1 > 0) {
            l = a2-a1;
        }
        else l = a2;
        if(b1 > 0) {
            h = b2-b1;
        }
        else h = b2;
    }
    return l*h;
}

int q2(int a1, int b1, int a2, int b2) {
    int l, h;    
    if(b2 <= 0) return 0;
    else if(a1 >= 0) return 0;
    else {
        if(a2 >= 0) {
            l = 0-a1;
        }
        else l = a2-a1;
        if(b1 <= 0) {
            h = b2;
        }
        else h = b2-b1;
    }
    return l*h;
}

int q3(int a1, int b1, int a2, int b2) {
    int l, h;    
    if(a1 >= 0) return 0;
    else if(b1 >= 0) return 0;
    else {
        if(a2 >= 0) {
            l = 0-a1;
        }
        else l = a2-a1;
        if(b2 >= 0) {
            h = 0-b1;
        }
        else h = b2-b1;
    }
    return l*h;
}

int q4(int a1, int b1, int a2, int b2) {
    int l, h;    
    if(a2 <= 0) return 0;
    else if(b1 >= 0) return 0;
    else {
        if(a1 > 0) {
            l = a2-a1;
        }
        else l = a2;
        if(b2 < 0) {
            h = b2-b1;
        }
        else h = 0-b1;
    }
    return l*h;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

    int inx1, iny1, inx2, iny2;
    if(x3 >= x2 || x1 >= x4 || y1 >= y4 || y3 >= y2) {
        inx1 = 0;
        inx2 = 0;
        iny1 = 0;
        iny2 = 0;
    }
    else {
        if(x3 > x1) {
            if(x4 > x2) {
                inx1 = x3;
                inx2 = x2;
            }
            else {
                inx1 = x3;
                inx2 = x4;
            }
        }
        else {
            if(x4 > x2) {
                inx1 = x1;
                inx2 = x2;
            }
            else {
                inx1 = x1;
                inx2 = x4;
            }
        }
        if(y3 > y1) {
            if(y4 > y2) {
                iny1 = y3;
                iny2 = y2;
            }
            else {
                iny1 = y3;
                iny2 = y4;
            }
        }
        else {
            if(y4 > y2) {
                iny1 = y1;
                iny2 = y2;
            }
            else {
                iny1 = y1;
                iny2 = y4;
            }
        }
    }


    /*
    printf("q1A = %d\n", q1(x1, y1, x2, y2));
    printf("q1B = %d\n", q1(x3, y3, x4, y4));
    printf("q1IN = %d\n", q1(inx1, iny1, inx2, iny2));
    
    printf("q2A = %d\n", q2(x1, y1, x2, y2));
    printf("q2B = %d\n", q2(x3, y3, x4, y4));
    printf("q2IN = %d\n", q2(inx1, iny1, inx2, iny2));
    
    printf("q3A = %d\n", q3(x1, y1, x2, y2));
    printf("q3B = %d\n", q3(x3, y3, x4, y4));
    printf("q3IN = %d\n", q3(inx1, iny1, inx2, iny2));
    
    printf("q4A = %d\n", q4(x1, y1, x2, y2));
    printf("q4B = %d\n", q4(x3, y3, x4, y4));
    printf("q4IN = %d\n", q4(inx1, iny1, inx2, iny2));
    */

    int q1A, q1B, q1IN;
    int q2A, q2B, q2IN;
    int q3A, q3B, q3IN;
    int q4A, q4B, q4IN;

    q1A = q1(x1, y1, x2, y2);
    q1B = q1(x3, y3, x4, y4);
    q1IN = q1(inx1, iny1, inx2, iny2);

    q2A = q2(x1, y1, x2, y2);
    q2B = q2(x3, y3, x4, y4);
    q2IN = q2(inx1, iny1, inx2, iny2);

    q3A = q3(x1, y1, x2, y2);
    q3B = q3(x3, y3, x4, y4);
    q3IN = q3(inx1, iny1, inx2, iny2);

    q4A = q4(x1, y1, x2, y2);
    q4B = q4(x3, y3, x4, y4);
    q4IN = q4(inx1, iny1, inx2, iny2);

    /*
    printf("%d %d %d\n", q1A, q1B, q1IN);
    printf("%d %d %d\n", q2A, q2B, q2IN);
    printf("%d %d %d\n", q3A, q3B, q3IN);
    printf("%d %d %d\n", q4A, q4B, q4IN);
    */

    int A1 = 0, A2 = 0, A3 = 0, A4 = 0;
    A1 = q1A + q1B - q1IN;
    A2 = q2A + q2B - q2IN;
    A3 = q3A + q3B - q3IN;
    A4 = q4A + q4B - q4IN;
    
    printf("%d\n%d\n%d\n%d\n", A1, A2, A3, A4);
}