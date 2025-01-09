#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], parent[MAX], v, v1, v2, i, j, rno, cno, tot_e, count = 1, mincost = 0;

int find(int x) {
    return parent[x];
}

int unionset(int x, int y) {
    if (x != y) {
        for (int k = 1; k <= v; k++) {
            if (parent[k] == y) {
                parent[k] = x;
            }
        }
        return 1;
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    // Initialize parent array
    for (i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Input cost matrix
    printf("Enter the cost matrix:\n");
    for (i = 1;i <= v; i++){
        for ( j = i+1; j <= v;j++){
            printf("Enter the cost[%d,%d]:", i, j);
            scanf("%d",&cost[i][j]);
            cost[j][i] = cost[i][j];

            if (cost[i][j] == 0){
                cost[i][j] = cost[j][i] = INF;
            }
        }
        cost[i][i] = INF;
    }

    tot_e = v - 1; // Number of edges in the MST

    while (count <= tot_e) {
        int c = INF;

        // Find the smallest edge
        for (i = 1; i <= v; i++) {
            for (j = 1; j <= v; j++) {
                if (cost[i][j] < c) {
                    c = cost[i][j];
                    v1 = i;
                    v2 = j;
                }
            }
        }

        // Find parents of the vertices
        rno = find(v1);
        cno = find(v2);

        // If the edge doesn't form a cycle, include it in the MST
        if (unionset(rno, cno)) {
            printf("Edge included: %d -> %d, Cost: %d\n", v1, v2, c);
            mincost += c;
            count++;
        }

        // Mark the edge as used
        cost[v1][v2] = cost[v2][v1] = INF;
    }

    printf("Minimum cost of the spanning tree: %d\n", mincost);
    return 0;
}
