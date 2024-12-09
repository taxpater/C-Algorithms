#include <stdio.h>
#define SIZE 10

// Definition of the non dynamic stack object.
typedef struct stack {
	int top ; // Initialisation of the top indicator. 
	int arr[SIZE]; // The table that will hold the values of our stack.
} Stack;

// Function that initialises the stack.
void initStack(Stack *s) {
	s->top = -1; //The top indicator is set as -1 to indicate an empty stack.
}

// Function that checks whether a non dynamic stack is empty.
int stackIsEmpty(Stack *s) {
	if (s->top == -1) {
		// Since the stack is being implemented using a non dynamic structure - a table -
		//if the indicator for the position of top is equal to -1, the stack must be empty.
		printf("The stack is empty! "); 
		return 1; // Logical true.
	} else return 0; // Logical false.
}

// Function that checks whether a non dynamic stack is full.
int stackIsFull(Stack *s) {
	if (s->top == SIZE - 1) {
		// Since the stack is being implemented using a non dynamic structure - a table -
		//if the indicator for the position of top is equal to SIZE - 1, the table must be full.
		printf("The stack is full! ");
		return 1; // Logical true.
	} else return 0; // Logical false.
}

// Function that pushes a provided integer to the stack, if possible.
int push(Stack *s, int num) {
	if (stackIsFull(s)) {
		// If the stack is full, pushing into it is impossible.
		printf("Pushing of %d to the stack has failed.\n", num);
		return -1; // Error indicator.
	}
	
	(s->top)++;
	s->arr[s->top] = num;
	return 0; // Process completed successfully.
}

// Function that pops an integer from the stack, if possible.
int pop(Stack *s) {
	if (stackIsEmpty(s)) {
		// If the stack is empty, popping from it is impossible.
		printf("Popping from the stack has failed.\n");
		return -1; // Error indicator.
	}
	
	int temp = s->arr[s->top];
	
	if (!s->top) {
		s->top = -1;
	} else {
		(s->top)--;
	}
	return temp;
}

int top(Stack *s) {
	if (stackIsEmpty(s)) {
		// If the stack is empty, there is nothing to return at the top of the stack.
		printf("Cannot return the top object of an empty stack.\n");
		return -1; // Error indicator.
	}
	return s->arr[s->top];
}

void printStack(Stack *s) {
	if (stackIsEmpty(s)) {
		// If the stack is empty, it is stated by the stackIsEmpty function.
		return;
	}
	int i;
	printf("Stack:\n");
	for (i=s->top; i>=0; i--) {
		printf("\n%d",s->arr[i]);
	}
}

// Function that returns the current size of the stack.
int size(Stack *s) {
	return (s->top) + 1; // We return this since the table's first position is 0.
}

// Example code containing the usage for all functions.
int main(void) {
	Stack s;
	initStack(&s);
	
	pop(&s);
	push(&s, 20);
	size(&s);
	top(&s);
	pop(&s);
	printStack(&s);
	
	return 0;
}
