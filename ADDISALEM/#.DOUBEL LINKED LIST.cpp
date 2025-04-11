//STRUCTURE each node has two pointer one of the next node and one to the previour node
// Traversal can move bothe forward and backward also colled bidirectional
//This helpes in accessing both successor node and predecessor node from the give node position.
#include <iostream>

// Define the node structure
struct Node {
	int data;              // Data part
	struct Node *next;     // Pointer to next node
	struct Node *prev;     // Pointer to previous node
};

// Function to create a new node
struct Node *createNode(int data) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
	newNode->data = data;     // Set data
	newNode->next = NULL;     // Initialize next as NULL
	newNode->prev = NULL;     // Initialize prev as NULL
	return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node **head, int data) {
	struct Node *newNode = createNode(data); // Create new node

	// If list is empty

	if (*head == NULL) {
		*head = newNode;     // New node becomes head
		return;
	}

	// Traverse to the last node
	struct Node *temp = *head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;     // Last node's next points to new node
	newNode->prev = temp;     // New node's prev points to last node
}

// Function to print list from beginning to end
void printForward(struct Node *head) {
	struct Node *temp = head;
	printf("Forward: ");

	while (temp != NULL) {
		printf("%d <-> ", temp->data); // Print current node
		temp = temp->next;             // Move to next node
	}
	printf("NULL\n");
}

// Function to print list from end to beginning
void printBackward(struct Node *head) {

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	// Go to last node
	struct Node *temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	// Traverse backward using prev
	printf("Backward: ");

	while (temp != NULL) {
		printf("%d <-> ", temp->data);
		temp = temp->prev;
	}
	printf("NULL\n");
}

// Main function to test the list
int main() {
	struct Node *head = NULL;  // Start with an empty list

	// Insert nodes
	insertEnd(&head, 10);
	insertEnd(&head, 20);
	insertEnd(&head, 30);

	// Print the list in both directions
	printForward(head);   // Output: 10 <-> 20 <-> 30 <-> NULL
	printBackward(head);  // Output: 30 <-> 20 <-> 10 <-> NULL

	return 0;
}