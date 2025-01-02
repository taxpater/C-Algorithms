#include <stdio.h>
#include <stdlib.h>

// Definition of the node struct for the binary search tree.
typedef struct Node {
	int key;
	struct Node* right;
	struct Node* left;
	struct Node* parent;
} Node;

// Definition of the binary search tree struct.
typedef struct BST {
	Node* root;
} BST;

void BSTPreorderWalk(Node *x) {
	if (x != NULL) {
	printf("%d ", x->key);
	BSTPreorderWalk(x->left);
	BSTPreorderWalk(x->right);
	}
}

void BSTPostorderWalk(Node *x) {
	if (x != NULL) {
	postorder_tree_walk(x->left);
	postorder_tree_walk(x->right);
	printf("%d ", x->key);
	}
}

void BSTInorderWalk(Node *x) {
	if (x != NULL) {
	inorder_tree_walk(x->left);
	printf("%d ", x->key);
	inorder_tree_walk(x->right);
	}
}

Node* tree_search(Node* x, int k) {
	if (x == NULL || x->key == key) {
		return x;
	}
	if (k < x.key) {
		return tree_search(x->left, k);
	}
	return tree_search(x->right, k);
}

Node* BSTMinimum(Node* x) {
	Node* current = x;
	while (x->left != NULL)
		current = current->left;
	return current;
}

Node* BSTMaximum(Node* x) {
	Node* current = x;
	while (current->right != NULL)
		current = current->right;
	return current;
}
