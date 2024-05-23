#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int front, rear;
    int items[MAX];
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Function to insert an element into the queue (ENQUEUE)
void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = element;
    printf("Enqueued %d\n", element);
}

// Function to remove an element from the queue (DEQUEUE)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int element = q->items[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, reset queue after removing it
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return element;
}

// Function to display the elements in the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = q->front;
    printf("Queue elements are: ");
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, element;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;
            case 2:
                element = dequeue(&q);
                if (element != -1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
