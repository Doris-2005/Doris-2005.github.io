#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Max(int a, int b) {
    if(a >= b) return a;
    else return b;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int x = a*2-b;
    int p = 0;
    int ls = 1, us = 1, ds = 1;
    int w, dw, uw;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < x; j++) {
            scanf("%d", &w);
            if(i == 0 && j == 0) {
                dw = w;
            }
            else if(j < b) {
                if(dw == w) {
                    ds++;
                }
                else {
                    ls = Max(ls, ds);
                    ds = 1;
                    dw = w;
                }
            }
            else {
                if(j == b+1) {
                    uw = w;
                }
                else if(p == 0 || p == 3) {
                    if(dw == w) {
                        ds++;
                    }
                    else {
                        ls = Max(ls, ds);
                        ds = 1;
                        dw = w;
                    }
                }
                else if(p == 1 || p == 2) {
                    if(uw == w) {
                        us++;
                    }
                    else {
                        ls = Max(ls, us);
                        us = 1;
                        uw = w;
                    }
                }
                p++;
                p = p % 4;
            }
            if(i == n-1 && j == x-1) {
                ls = Max(ds, ls);
                ls = Max(us, ls);
            }
        }
        ls = Max(ls, us);
        us = 1;
    }
    printf("%d\n", ls);
}