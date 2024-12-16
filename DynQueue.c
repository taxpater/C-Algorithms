#include <stdio.h>
#include <stdlib.h>

// Definition of the node struct for the dynamic queue.
typedef struct Node {
	int key;
	struct Node *next;
} Node;

// Definition of the dynamic queue struct.
typedef struct DynQueue {
	int size;
	Node *front;
	Node *rear;
} DynStack;

// Function that initialises the dynamic queue.
void DynQueueInit(DynQueue *q) {
	q->size=0;
	q->front=NULL;
	q->rear=NULL;
}

// Function that checks whether a dynamic queue is empty using the size value of the DynQueue struct.
int DynQueueIsEmpty(DynQueue *q) {
	// Checking whether the queue's size is zero, which meant it is empty.
	if (!q->size) {
		printf("\nThe queue is empty! ");
		return 1; // Logical true.
	} else return 0; // Logical false.
}

void DynQueueEnqueue(DynQueue *qm int num) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->key=val;
	if (q->size==0) {
		q->front = new_node;
	}
	else {
		(q->rear)->next = new_node;
	}
	q->rear = new_node;
	new_node->next = NULL;
	q->size++;
}
