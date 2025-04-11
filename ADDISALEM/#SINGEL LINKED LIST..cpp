//STRUCTUR each node point to the naxt node
//TRAVERSAL can move only forward the list
// SINGEL LINKED LIST node are linked togather in some sequantial manner.
#include <iostream>

// Define the node structure
struct Node {
	int data;
	struct Node *next;
};
#include <stdio.h>

// Function to create a new node
struct Node *createNode(int data) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Function to append a node at the end
void appendNode(struct Node **head, int data) {
	struct Node *newNode = createNode(data);

	if (*head == NULL) {
		*head = newNode;
		return;
	}
	struct Node *temp = *head;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node *head) {
	struct Node *temp = head;

	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() {
	struct Node *head = NULL;
	appendNode(&head, 1);
	appendNode(&head, 2);
	appendNode(&head, 3);
	printList(head); // Output: 1 -> 2 -> 3 -> NULL
	return 0;
}