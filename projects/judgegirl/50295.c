#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int BestFitBin[1005];
int FirstFitBin[1005];
int WorstFitBin[1005];
int C;

int Bnow = 0;
int Fnow = 0;
int Wnow = 0;

bool ub = 0, uf = 0, uw = 0;

void BestFit(int x) {
    int p = 0;
    int src = C+1;
    if(ub == 0) {
        BestFitBin[0] = C;
        ub = 1;
    }
    for(int i = 0; i < Bnow+1; i++) {
        if(BestFitBin[i] >= x) {
            if(BestFitBin[i] < src) {
                src = BestFitBin[i];
                p = i;
            }
        }
        else {
            if(i == Bnow && src == C+1) {
                BestFitBin[i+1] = C;
                Bnow++;
            }
        }
        //printf("1. BestFitBin = %d, place = %d, i = %d, src = %d\n", BestFitBin[p], p, i, src);
    }
    //printf("2. x = %d, place = %d, BestFitBin = %d, Bnow = %d\n", x, p, BestFitBin[p], Bnow);
    BestFitBin[p] -= x;
    //printf("3. x = %d, place = %d, BestFitBin = %d, Bnow = %d\n", x, p, BestFitBin[p], Bnow);
}

void FirstFit(int y) {
    if(uf == 0) {
        FirstFitBin[0] = C;
        uf = 1;
    }
    for(int i = 0; i < Fnow+1; i++) {
        if(FirstFitBin[i] >= y) {
            //printf("2. y = %d, place = %d, FirstFitBin = %d, Fnow = %d\n", y, i, FirstFitBin[i], Fnow);
            FirstFitBin[i] -= y;
            //printf("3. y = %d, place = %d, FirstFitBin = %d, Fnow = %d\n", y, i, FirstFitBin[i], Fnow);
            break;
        }
        else {
            if(i == Fnow) {
                FirstFitBin[i+1] = C;
                Fnow++;
            }
        }    
    }
}

void WorstFit(int z) {
    int p = 0;
    int lrc = -1;
    if(uw == 0) {
        WorstFitBin[0] = C;
        uw = 1;
    }
    for(int i = 0; i < Wnow+1; i++) {
        if(WorstFitBin[i] >= z) {
            if(WorstFitBin[i] > lrc) {
                lrc = WorstFitBin[i];
                p = i;
            }
        }
        else {
            if(i == Wnow && lrc == -1) {
                WorstFitBin[i+1] = C;
                Wnow++;
            }
        }
    }
    //printf("2. z = %d, place = %d, WorstFitBin = %d, wnow = %d\n", z, p, WorstFitBin[p], Bnow);
    WorstFitBin[p] -= z;
    //printf("3. z = %d, place = %d, WorstFitBin = %d, Wnow = %d\n", z, p, WorstFitBin[p], Bnow);
}

int main() {
    int m;
    scanf("%d %d", &m, &C);
    int s;
    for(int i = 0; i < m; i++) {
        scanf("%d", &s);
        BestFit(s);
        FirstFit(s);
        WorstFit(s);
    }
    //printf("BestFitBin[Bnow] = %d\n", BestFitBin[Bnow]);
    if(BestFitBin[Bnow] == C) Bnow--;
    if(FirstFitBin[Fnow] == C) Fnow--;
    if(WorstFitBin[Wnow] == C) Wnow--;
    printf("%d %d %d\n", Bnow+1, Fnow+1, Wnow+1);
}