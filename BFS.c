#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices in the graph

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Graph {
    int numVertices;
    int adjMatrix[MAX][MAX];
    int visited[MAX];
};

void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void createGraph(struct Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;  // For undirected graph
}

void bfs(struct Graph* g, int startVertex) {
    struct Queue q;
    initializeQueue(&q);

    g->visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("Visited %d\n", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !g->visited[i]) {
                g->visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    struct Graph g;
    int vertices = 6;

    createGraph(&g, vertices);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 4);
    addEdge(&g, 3, 5);
    addEdge(&g, 4, 5);

    bfs(&g, 0);

    return 0;
}
