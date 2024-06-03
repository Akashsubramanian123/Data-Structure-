#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void DFS(int adj[][MAX], int n, int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            DFS(adj, n, i, visited);
        }
    }
}

int main() {
    int n = 6;
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    int visited[MAX] = {0};

    int start = 0;
    printf("Depth First Search starting from vertex %d:\n", start);
    DFS(adj, n, start, visited);

    return 0;
}
