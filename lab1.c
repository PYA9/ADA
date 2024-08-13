#include<stdio.h>
#include<stdlib.h>

int i, j, k, a, b, u, v, n;
int min, mincost = 0;
int cost[10][10], parent[10];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return i;
    }
    return 0;
}

void main() {
    int ne;

    printf("Implement of Kruskal's algorithm \n");
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix : \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of minimum cost spanning tree:\n");
    ne = 1;
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("Edge %d : (%d -> %d), Cost : %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("The cost of minimum spanning tree is %d\n", mincost);
}

