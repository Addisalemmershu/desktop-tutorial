//CIRCULAR DOUBLE LINKED LIST is the next pointer of the last node point to the first node
//Each node containe a data field,A pointerof the last node points to the first node
//The prev pointer of the first node points to the last node.
#include <iostream>

// Define the node structure
struct Node {
	int data;              // Data stored in the node
	struct Node *next;     // Pointer to the next node
	struct Node *prev;     // Pointer to the previous node
};

// Function to create a new node
struct Node *createNode(int data) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
	newNode->data = data;     // Set the data
	newNode->next = newNode;  // Initially, next points to itself (circular)
	newNode->prev = newNode;  // prev also points to itself (circular)
	return newNode;           // Return the new node
}

// Function to insert at the end of the circular doubly linked list
void insertEnd(struct Node **head, int data) {
	struct Node *newNode = createNode(data); // Create a new node

	// If the list is empty, new node becomes the head

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	// If list is not empty, insert at the end
	struct Node *last = (*head)->prev;  // Last node is the one before head

	newNode->next = *head;        // New node points to head (circular)
	newNode->prev = last;         // New node's prev points to last node
	last->next = newNode;         // Last node's next points to new node
	(*head)->prev = newNode;      // Head's prev is updated to new node
}

// Function to print the list forward
void printForward(struct Node *head) {

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct Node *temp = head;
	printf("Forward: ");

	do {
		printf("%d <-> ", temp->data);  // Print current node
		temp = temp->next;              // Move to next node
	} while (temp != head);             // Stop when back at head
	printf("HEAD\n");
}

// Function to print the list backward
void printBackward(struct Node *head) {

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct Node *last = head->prev;  // Start from the last node
	struct Node *temp = last;
	printf("Backward: ");

	do {
		printf("%d <-> ", temp->data);  // Print current node
		temp = temp->prev;              // Move to previous node
	} while (temp != last);             // Stop when back at last
	printf("HEAD\n");
}

// Main function to test the code
int main() {
	struct Node *head = NULL;  // Start with an empty list

	// Insert some values
	insertEnd(&head, 10);
	insertEnd(&head, 20);
	insertEnd(&head, 30);

	// Print in both directions
	printForward(head);   // Expected: 10 <-> 20 <-> 30 <-> HEAD
	printBackward(head);  // Expected: 30 <-> 20 <-> 10 <-> HEAD

	return 0;
}
