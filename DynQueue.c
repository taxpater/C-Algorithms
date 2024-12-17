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
} DynQueue;

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

// Function that adds a provided integer to the provided dynamic queue.
void DynQueueEnqueue(DynQueue *q, int num) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->key=num;
	if (q->size==0) {
		q->front = new_node;
	}
	else {
		(q->rear)->next = new_node;
	}
	q->rear = new_node;
	new_node->next = NULL;
	q->size++;
}

// Function that removes a member from the provided dynamic queue.
int DynQueueDequeue(DynQueue *q) {
	int num;
	struct Node *tmp;
	// Ensuring that the dynamic queue has at least one member before attempting to pop from it.
	if (!DynQueueIsEmpty(q)) {
		num = (q->front)->key;
		tmp = q->front;
		q->front = (q->front)->next;
		
		if (q->size == 1) {
			q->rear = (q->rear)->next;
		}
		q->size--;
		free(tmp);
		return num;
	} else {
		printf("There is nothing to remove from the queue!");
		return -1; // Error indicator.
	}
}

// Function that returns the first key of the queue.
int DynQueueFirst(DynQueue *q) {
	// Ensuring that the dynamic queue has at least one member before attempting to find it's top.
	if (DynQueueIsEmpty(q)) {
		printf("There is no first member (the queue is empty).");
		return -1; // Error indicator showing that there is no first key.
	} else {
		return (q->front)->key;
	}
}

// Function that returns the last key of the queue.
int DynQueueLast(DynQueue *q) {
	if (DynQueueIsEmpty(q)) {
		printf("There is no last member (the queue is empty).");
		return -1; // Error indicator showing that there is no last key.
	} else {
		return (q->rear)->key;
	}
}

// Function that returns the current size of the provided queue.
int DynQueueSize(DynQueue *q) {
	return q->size;
}

// Function that prints the dynamic queue.
void DynQueuePrint(DynQueue *q) {
	// Ensuring that the dynamic queue has at least one member before attempting to write it's contents.
	if (DynQueueIsEmpty(q)) {
		printf("Cannot print an empty queue.");
		return;
	}
	else {
		Node *t = q->front;
		printf("\nQueue:\n| ");
		while(t != NULL) {
			printf("%d | ", t->key);
			t=t->next;
		}
		printf("\n");
	}
}

// Example code containing the usage for all functions.
int main(void) {
	DynQueue q;
	DynQueueInit(&q);
	DynQueueDequeue(&q);
	DynQueueEnqueue(&q, 1);
	DynQueueEnqueue(&q, 3);
	DynQueueEnqueue(&q, 2);
	DynQueueDequeue(&q);
	DynQueueEnqueue(&q, 23);
	printf("%d", DynQueueFirst(&q));
	printf("%d", DynQueueLast(&q));
	DynQueuePrint(&q);
	return 0;
}
