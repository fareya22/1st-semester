#include <bits/stdc++.h>
#include "graph.cpp"
using namespace std;
int newMatrix[20][20];
char color[1000];
int previous[1000], f[1000], d[1000];
int maxi;
 #define inf 100000
int times;

void DFS_Visit(int u, int maxi) {
    color[u] = 'g';
    times++;
    d[u] = times;
    int v;

    for (int i = 1; i <= maxi; i++) {
        if (g[u][i] == 1) {
            v = i;
            if (color[v] == 'w') {
                previous[v] = u;
                DFS_Visit(v, maxi);
            }
        }
    }
    color[u] = 'B';
    times++;
    f[u] = times;
}

void DFS(int maxi,int s) {
    for (int i = 1; i <= maxi; i++) {
        color[i] = 'w';
        previous[i] = -1;
        f[i] = inf;
        d[i] = inf;
    }
    times = 0;
    DFS_Visit(s, maxi);
    for (int i = 1; i <= maxi; i++) {
        if (color[i] == 'w') {
            DFS_Visit(i, maxi);
        }
    }
}

int main() {

    make_graph();
 /*   printf("Enter the number of vertices and edges of the graph:\n");
    int m, n;
    scanf("%d%d", &m, &n);
    int g[m + 1][m + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            g[i][j] = 0;
        }
    }*/
   // int maxi = m;
  /*  printf("Enter the corresponding edges of the vertices:\n");
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
    }
    int s;
    printf("Enter the source node: ");
    scanf("%d", &s);*/
   maxi = totalLine;



    for(int i=0;i<=totalLine;i++){
        for(int j=0;j<=totalLine;j++){
            newMartix[i][j]=g[i][j];
        }
    }

    DFS(maxi, 0);
    for (int i = 1; i <= maxi; i++) {
        printf("parent of %d node is %d\n", i, previous[i]);
        printf("color of %d node is %c\n", i, color[i]);
        printf("discovery time of %d node is %d\n", i, d[i]);
        printf("final time of %d node is %d\n", i, f[i]);
        printf("\n");
    }

    return 0;
}
