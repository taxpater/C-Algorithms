#include <stdio.h>
#include <stdlib.h>

// Definition of the node object for the dynamic stack.
typedef struct Node {
	int key;
	struct Node *next;
} Node;

// Definition of the dynamic stack object.
typedef struct DynStack {
	Node *top;
	int size;
} DynStack;

// Function that initialises the dynamic stack.
void DynStackInit(DynStack *s) {
	s->size=0;
	s->top=NULL;
}

// Function that checks whether a dynamic stack is empty using the size value of the DynStack struct.
int DynStackIsEmpty(DynStack *s) {
	// Checking whether 
	if (!s->size) {
		printf("\nThe stack is empty! ");
		return 1; // Logical true.
	} else return 0; // Logical false.
}

// Function that pushes a provided integer to the provided dynamic stack.
void DynStackPush(DynStack *s, int num) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->key = num;
	newNode->next = s->top;
	s->size++;
	s->top = newNode; 
}
// Function that pops from the provided dynamic stack.
int DynStackPop(DynStack *s) {
	// Ensuring that the dynamic queue has at least one member before attempting to pop from it.
	if (!DynStackIsEmpty(s)) {
		int num = (s->top)->key;
		Node *tmp = s->top;
		s->top = (s->top)->next;
		s->size--;
		free(tmp);
		return num;
	} else return -1; // Error indicator.
}

// Function that returns the value of the first integer in the stack.
int DynStackTop(DynStack *s) {
	// Ensuring that the dynamic queue has at least one member before attempting to find it's top.
	if (DynStackIsEmpty(s)) {
		printf("There is no top.");
		return -1; // Error indicator showing that there is no top (empty stack).
	} else return (s->top)->key;
}

// Function that returns the current size of the provided stack.
int DynStackSize(DynStack *s) {
	return s->size;
}

// Function that prints the dynamic stack.
void DynStackPrint(DynStack *s) {
	// Ensuring that the dynamic queue has at least one member before attempting to write it's contents.
	if (DynStackIsEmpty(s)) {
		printf("Cannot print an empty stack.");
	} else {
		Node *t = s->top;
		printf("\nStack:\n");
		while (t != NULL) {
			printf("%d\n", t->key);
			t = t->next;
		}
		printf("\n");
	}
}

// Example code containing the usage for all functions.
int main(void) {
	DynStack s;
	DynStackInit(&s);
	DynStackPush(&s, 4);
	DynStackPush(&s, 3);
	DynStackPush(&s, 13);
	DynStackPush(&s, 2);
	DynStackPop(&s);
	DynStackPush(&s, 28);
	DynStackPrint(&s);
	return 0;
}
