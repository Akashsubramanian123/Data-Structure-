#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Structure to represent each slot in the hash table
typedef struct {
    int key;
    int isOccupied; // 0 if slot is empty, 1 if occupied
} HashTable;

// Function to initialize the hash table
void initHashTable(HashTable table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = -1;
        table[i].isOccupied = 0;
    }
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key into the hash table
void insert(HashTable table[], int key) {
    int index = hashFunction(key);
    int startIndex = index;

    // Linear probing to find the next available slot
    while (table[index].isOccupied) {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            printf("Hash table is full!\n");
            return;
        }
    }

    table[index].key = key;
    table[index].isOccupied = 1;
    printf("Inserted key %d at index %d\n", key, index);
}

// Function to search for a key in the hash table
int search(HashTable table[], int key) {
    int index = hashFunction(key);
    int startIndex = index;

    // Linear probing to find the key
    while (table[index].isOccupied) {
        if (table[index].key == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            break;
        }
    }

    return -1; // Key not found
}

// Function to display the hash table
void display(HashTable table[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].isOccupied) {
            printf("Index %d: Key %d\n", i, table[i].key);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    HashTable table[TABLE_SIZE];
    initHashTable(table);

    int choice, key, index;

    while (1) {
        printf("\nHash Table Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(table, key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                index = search(table, key);
                if (index != -1) {
                    printf("Key %d found at index %d\n", key, index);
                } else {
                    printf("Key %d not found in the hash table\n", key);
                }
                break;
            case 3:
                display(table);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
