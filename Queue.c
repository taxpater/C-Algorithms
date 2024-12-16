include <stdio.h>
#define SIZE 10

// Definition of the non dynamic queue object.
typedef struct {
	int front;
	int rear;
	int arr[SIZE];
} Queue;

// Function that initialises the queue.
void initQueue(Queue *q) {
	q->front = q->rear = -1; //The front & rear indicators are set as -1 to indicate an empty queue.
}

// Function that checks whether a non dynamic queue is empty.
int QueueIsEmpty(Queue *q) {
	if ((q->front) == (q->rear) && (q->front) == -1) {
		// Since the queue is being implemented using a non dynamic structure - a table -
		//if the indicator for the position of top or the rear is equal to -1, the queue must be empty.
		printf("The queue is empty! ");
		return 1; // Logical true.
	} else return 0; // Logical false.
}

// Function that checks whether a non dynamic queue is full.
int QueueIsFull(Queue *q) {
	if (q->rear == SIZE-1) {
		// Since the queue is being implemented using a non dynamic structure - a table -
		//if the indicator for the position of the rear is equal to SIZE - 1, the queue must be full.
		printf("The queue is full! ");
		return 1; // Logical true.
	} else return 0; // Logical false.
}

// Function that adds a provided integer to the queue, if possible.
int Enqueue(Queue *q, int num) {
	if (QueueIsFull(q)) {
		// If the queue is full, pushing into it is impossible.
		printf("Enqueueing of %d failed!\n", num);
		return -1; // Error indicator.
	}
	
	(q->rear)++; // Increase of the rear indicator.
	q->arr[q->rear] = num; // Saving of the pushed number on the data structure.
	return 1; // Process completed successfully.
}

// Function that removes an integer from the queue in the position "front" if possible.
int Dequeue(Queue *q) {
	if (QueueIsEmpty(q)) {
		// If the queue is full, poping from it is impossible.
		printf("Dequeueing failed!\n");
		return -1; // Error indicator.
	// Checking whether the queue has only one integer inside,
	// meaning that removing that integer empties it.
	} else if ((q->front) + 1 == q->rear) {
		int num = q->arr[q->front++];
		q->front = q->rear = -1;
	}
	
	(q->front)++; // Increase of the front indicator
	
	int num = q->arr[(q->front)]; // Reading and returning
	return num; // the integer that was removed from the queue.
}

// Function that returns the first member of the queue.
int First(Queue *q) {
	// Ensuring that the queue has at least one integer before attempting to read from it.
	if (QueueIsEmpty(q)) {
		printf("There is no first member in the queue!\n");
		return -1; // Error indicator.
	}
	
	return q->arr[q->front+1];
}

// Function that returns the last member of the queue.
int Last(Queue *q) {
	// Ensuring that the queue has at least one integer before attempting to read from it.
	if (QueueIsEmpty(q)) {
		printf("There is no last member in the queue!\n");
		return -1; // Error indicator.
	}
	
	return q->arr[q->rear];
}

// Function that returns the current size of the queue.
int QueueSize(Queue *q) {
	return q->rear - q->front;
	// In any case of the current implementation, the correct size will be outputed by the
	// above calculation. 
}

// Function that prints the queue.
void PrintQueue(Queue *q) {
	// Ensuring that the queue has at least one integer before attempting to print its contents.
	if (QueueIsEmpty(q)) {
		printf("There is nothing to print in the queue!\n");
		return;	
	}
	
	int i;
	printf("Queue: ");
	// Printing of the queue's contents
	for (i=(q->front)+1; i<=(q->rear); i++) {
		printf("|%d", q->arr[i]);
	}
	printf("|\n");
}

// Example code containing the usage for all functions.
int main(void) {
	Queue q;
	int num;
	initQueue(&q);
	num = Dequeue(&q);
	Enqueue(&q,5);
	Enqueue(&q,3);
	Enqueue(&q,4);
	printf("First: %d\n", First(&q));
	printf("Last: %d\n", Last(&q));
	PrintQueue(&q);
	num = Dequeue(&q);
	num = Dequeue(&q);
	return 0;
}
