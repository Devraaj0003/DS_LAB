#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], visited[MAX], v;

int main() {
    int i, j, v1, v2, count = 0, mincost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    // Input the cost adjacency matrix
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

    // Initialize visited array
    for (i = 1; i <= v; i++) {
        visited[i] = 0;
    }

    visited[1] = 1; // Start from vertex 1

    printf("Edges in the Minimum Spanning Tree:\n");
    while (count < v - 1) {
        int min = INF;
        v1 = -1;
        v2 = -1;

        // Find the smallest edge connecting visited and unvisited vertices
        for (i = 1; i <= v; i++) {
            if (visited[i]) { // Consider only visited vertices
                for (j = 1; j <= v; j++) {
                    if (!visited[j] && cost[i][j] < min) { // Check unvisited vertices
                        min = cost[i][j];
                        v1 = i;
                        v2 = j;
                    }
                }
            }
        }

        if (v1 != -1 && v2 != -1) {
            printf("Edge: %d -> %d, Cost: %d\n", v1, v2, min);
            mincost += min;
            visited[v2] = 1; // Mark vertex `v2` as visited
            count++;
        }
    }

    printf("Minimum cost of the spanning tree: %d\n", mincost);
    return 0;
}
