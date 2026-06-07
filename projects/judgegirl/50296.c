#include<stdio.h>
#include<stdlib.h>

int adj[501][501];
int vis[501];
int tot[501];
int n;
int sp;
int t;

void traverse(int x) {
    t++;
    int p;
    int sedge = 1000001;
    vis[x] = 1;

    for(int j = 0; j < n; j++) {
        if(x == sp && j == sp) continue;
        if(t == n) {
            sedge = adj[x][sp];
            p = sp;
        }
        else {
            if(vis[j] == 1) continue;
            if(adj[x][j] <= sedge) {
                sedge = adj[x][j];
                p = j;
            }
        }        
    }
    tot[sp] += sedge;
    vis[p] = 1;
    //printf("Starting point = %d, from = %d, now = %d, edge = %d\n", sp, x, p, sedge);
    if(p != sp) traverse(p);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
        tot[i] = 0;
    }
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }*/

    if(n == 1) printf("%d %d\n", 1, 0);
    else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                vis[j] = 0;
            }
            t = 0;
            sp = i;
            traverse(i);
        }
        int mintot = tot[0];
        int minver = 0;
        for(int i = 1; i < n; i++) {
            if(tot[i] <= mintot) {
                mintot = tot[i];
                minver = i;
            }
        }
        printf("%d %d\n", minver+1, mintot);
    }
}