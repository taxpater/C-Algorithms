#include <stdio.h>
#define SIZE 10

// Definition of the non dynamic circular queue object.
typedef struct {
	int front;
	int rear;
	int arr[SIZE];
} CQueue;

// Function that initialises the circular queue.
void initCQueue(CQueue *q) {
	q->front = q->rear = -1; //The front & rear indicators are set as -1 to indicate an empty queue.
}

// Function that checks whether a non dynamic queue is empty.
int CQueueIsEmpty(CQueue *q) {
	if ((q->front) == -1) {
		// Since the circular queue is being implemented using a non dynamic structure - a table -
		//if the indicator for the position of top or the rear is equal to -1, the queue must be empty.
		printf("The queue is empty! ");
		return 1; // Logical true.
	} else return 0; // Logical false.
}

// Function that checks whether a non dynamic circular queue is full.
int CQueueIsFull(CQueue *q) {
	// Since the circular queue is being implemented using a non dynamic structure - a table -
	// there are two scenarios where the queue is full:
	// 1. The queue's rear is equal to it's front - 1,
	// 2. The queue's rear is equal to SIZE - 1 and it's front is equal to 0,
	if ((q->rear == (q->front) - 1) || (q->rear == SIZE - 1 && q->front == 0)) {
		printf("The queue is full! ");
		return 1; // Logical true.
	} else return 0; // Logical false.
}

// Function that pushes a provided integer to the circular queue, if possible.
int Enqueue(CQueue *q, int num) {
	if (CQueueIsFull(q)) {
		// If the circular queue is full, pushing into it is impossible.
		printf("Enqueueing of %d failed!\n", num);
		return -1; // Error indicator.
	} else if ((q->front) == -1) {
		// If the circular queue is empty and we attempt to add a new member inside of it,
		// we have to first initialise the front and rear indicator to the 0 position.
		q->front = q->rear = 0;
	} else if ((q->rear == SIZE - 1 && q->front != 0)) {
		// If the queue's rear has reached the end of the table and there is an empty space in the beginning
		// of it, we have to set the rear as 0.
		q->rear = 0;
	} else {
		(q->rear)++;
	}
	
	q->arr[q->rear] = num;
	return 1; // Process completed successfully.
}

int Dequeue(CQueue *q) {
	// Holding the current value of the front, in preparation to remove it from the queue.
	int data = q->arr[q->front];
	
	if (CQueueIsEmpty(q)) {
		// If the queue is empty, you cannot dequeue from it.
		printf("Dequeueing failed!\n");
		return -1;
	} else if (q->front == SIZE - 1) {
		// If the queue's front is at the final position of the table (SIZE -1), dequeueing
		// should move the front to the first position (0).
		q->front = 0;
	} else if (q->front == q->rear) {
		// If the queue has one final integer inside, we "empty" it by reinitialising it.
		initCQueue(q);
	} else {
		// Moving the front indicator.
		(q->front)++;
	}
	
	return data;
}

int First(CQueue *q) {
	// Ensuring that the queue has at least one integer before attempting to read from it.
	if (CQueueIsEmpty(q)) {
		printf("There is no first member in the queue!\n");
		return -1;
	}
	
	return q->arr[q->front];
}

int Last(CQueue *q) {
	// Ensuring that the queue has at least one integer before attempting to read from it.
	if (CQueueIsEmpty(q)) {
		printf("There is no last member in the queue!\n");
		return -1;
	}
	
	return q->arr[q->rear];
}

int QueueSize(CQueue *q) {
	if (q->rear >= q->front) {
		return q->rear - q->front + 1;
	}
	else {
		return (SIZE-q->front)+(q->rear+1);
	}
}

void PrintQueue(CQueue *q) {
	int i;
	// If the queue is empty, there is nothing to print from it.
	if(CQueueIsEmpty(q)) {
		printf("Queue is empty!\n");
	}
	// If the queue hasn't "folded", we print it procedurally.
	if (q->rear >= q->front) {
        printf("Queue:");
		for (i = q->front; i <= q->rear; i++)
            printf("|%d", q->arr[i]);
        printf("|\n");
	}
	// If the queue has "folded", we print it in two parts. One part from the current position of
	// front to the last position (SIZE), and then from the first position (0) to the rear.
	else {
		printf("Queue:");
		for (i = q->front; i < SIZE; i++)
			printf("%d\t", q->arr[i]);
		for (i = 0; i <= q-> rear; i++)
			printf("%d\t", q->arr[i]);
		printf("|\n");
	}
}

// Example code containing the usage for all functions.
int main(void) {
	CQueue p;
	initCQueue(&p);
	int num;
	num = Dequeue(&p);
	Enqueue(&p,5);
	Enqueue(&p,3);
	PrintQueue(&p);
	Enqueue(&p,4);
	printf("First: %d\n", First(&p));
	printf("Last: %d\n", Last(&p));	
	num = Dequeue(&p);
	num = QueueSize(&p);
	num = Dequeue(&p);
	return 0;
}
