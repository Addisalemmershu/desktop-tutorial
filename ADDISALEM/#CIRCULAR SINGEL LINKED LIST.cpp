//CIRCULAR SINGEL is each node contains data and pointer to the next node.
//The last nodes pointer does not point to null like in anormal singel linked list
// Instead the last node point back to the first node forming a circular structure.
#include <iostream>

// Define the structure for a node
struct Node {
	int data;            // Data field
	struct Node *next;   // Pointer to the next node
};

// Function to create a new node
struct Node *createNode(int data) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
	newNode->data = data;     // Set the data
	newNode->next = NULL;     // Initialize next to NULL (for now)
	return newNode;           // Return the new node
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node **head, int data) {
	struct Node *newNode = createNode(data); // Create a new node

	// If the list is empty

	if (*head == NULL) {
		newNode->next = newNode; // Point to itself (only one node)
		*head = newNode;         // Make new node the head
		return;
	}

	// If list is not empty
	struct Node *temp = *head;

	while (temp->next != *head) {
		temp = temp->next; // Traverse to the last node
	}

	temp->next = newNode;   // Last node points to new node
	newNode->next = *head;  // New node points back to head (circular)
}

// Function to print the circular linked list
void printList(struct Node *head) {

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct Node *temp = head;
	printf("Circular List: ");

	do {
		printf("%d -> ", temp->data); // Print current node data
		temp = temp->next;            // Move to next node
	} while (temp != head);           // Stop when back to head
	printf("HEAD\n");
}

// Main function to test the circular linked list
int main() {
	struct Node *head = NULL; // Initialize an empty list

	// Insert nodes
	insertEnd(&head, 5);
	insertEnd(&head, 10);
	insertEnd(&head, 15);

	// Print the list
	printList(head);  // Expected output: 5 -> 10 -> 15 -> HEAD

	return 0;
}