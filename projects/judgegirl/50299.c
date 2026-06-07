#include "snake.h"
#include <stdio.h>
#include <stdlib.h>

void snake(int* first_element, int n, int* pointers[], int m) {
    for(int i = 0; i < m-1; i++) {
        int pos1 = pointers[i] - first_element;
        int pos2 = pointers[i+1] - first_element;

        int x1 = pos1 / n;
        int y1 = pos1 % n;
        int x2 = pos2 / n;
        int y2 = pos2 % n;

        if(pointers[i] == NULL) {
            return;
        }
        if(pos1 < 0 || pos1 >= n*n) {
            return;
        }

        if(i == m-2) {
            if(pointers[i+1] == NULL) {
                return;
            }
            if(pos2 < 0 || pos2 >= n*n) {
                return;
            }
        }
        
        if(x1 == x2) {
            if(y2 > y1) {
                for(int i = y1; i <= y2; i++, pos1++) {
                    *(first_element + pos1) = 1;
                }
            }
            else {
                for(int i = y1; i >= y2; i--, pos1--) {
                    *(first_element + pos1) = 1;
                }
            }
        }
        else if(y1 == y2) {
            if(x2 > x1) {
                for(int i = x1; i <= x2; i++, pos1+=n) {
                    *(first_element + pos1) = 1;
                }
            }
            else {
                for(int i = x1; i >= x2; i--, pos1-=n) {
                    *(first_element + pos1) = 1;
                }
            }
        }
        else if((x1-x2) == (y1-y2)) {
            if(x2 > x1) {
                for(int i = x1; i <= x2; i++, pos1+=(n+1)) {
                    *(first_element + pos1) = 1;
                }
            }
            else {
                for(int i = x1; i >= x2; i--, pos1-=(n+1)) {
                    *(first_element + pos1) = 1;
                }
            }
        }
        else if((x2-x1) == (y1-y2)) {
            if(x2 > x1) {
                for(int i = x1; i <= x2; i++, pos1+=(n-1)) {
                    *(first_element + pos1) = 1;
                }
            }
            else {
                for(int i = x1; i >= x2; i--, pos1-=(n-1)) {
                    *(first_element + pos1) = 1;
                }
            }
        }
        else return;
    }
}

/*
0  1  2  3  4
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24
*/