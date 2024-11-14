#include <stdio.h>
#define SIZE 10

typedef struct {
	int front;
	int rear;
	int tbl[SIZE];
} Queue;

void init_queue(Queue *s) {
	s->front = s->rear = -1;
}
int QueueIsEmpty(Queue *s) {
	if ((s->front) == (s->rear) && (s->front) == -1) {
		printf("The Queue is empty! ");
		return 1;
	} else return 0;
}

int QueueIsFull(Queue *s) {
	if (s->rear == SIZE-1) {
		printf("The Queue is full! ");
		return 1;
	}
	else return 0;
}

int QueueSize(Queue *s) {
	if (QueueIsEmpty(s)) {
		return 0;
	} else if (QueueIsFull(s)) {
		return SIZE;
	}
	return s->rear - s->front;
}
int Enqueue(Queue *s, int num) {
	if (QueueIsFull(s)) {
		printf("Enqueueing of %d failed!", num);
		return -1;
	}
	
	(s->rear)++;
	s->tbl[s->rear] = num;
	return 1;
}

int Dequeue(Queue *s) {
	if (QueueIsEmpty(s)) {
		printf("Dequeueing failed!");
		return -1;
	} else if ((s->front) + 1 == s->rear) {
		int num = s->tbl[s->front++];
		s->front = s->rear = -1;
	}
	
	(s->front)++;
	int num = s->tbl[(s->front)];
	return num;
}

int First(Queue *s) {
	if (QueueIsEmpty(s)) {
		printf("There is no first number!");
		return -1;
	}
	
	return s->tbl[s->front++];
}

int Last(Queue *s) {
	if (QueueIsEmpty(s)) {
		printf("There is no first number!");
		return -1;
	}
	
	return s->tbl[s->rear];
}

int main(void) {
	Queue p;
	int num;
	num = Dequeue(&p);
	Enqueue(&p,5);
	Enqueue(&p,3);
	Enqueue(&p,4);
	printf("%d", First(&p));
	printf("%d", Last(&p));	
	num = Dequeue(&p);
	num = Dequeue(&p);
}
