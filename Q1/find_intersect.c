// #include <stdio.h>
// #include <stdlib.h>


// typedef struct Node {
//   // Define the structure for a linked list node
// } Node;


// Node* createNewNode(int key) {
// // Function to create a new node
// }

// int getCount(Node* head) {
// // Function to get the count of nodes in a linked list
// }

// int getIntersectionNode(int d, Node* head1, Node* head2) {
//     // Function to get the intersection point of two linked lists
//     // Move the pointer of the longer list by 'd' nodes
//     // Traverse both lists, compare nodes
// }

// // Driver program to test the above function
// int main() {
//     // List A: 1 → 2 → 3 → 4 → 5 → 6


//     // List B: 9 → 8 → 6


//     // Find the intersection point


//     return 0;
// }
// C program to get intersection point of two linked list
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
typedef struct Node {
	int data;
	struct Node* next;
} Node;

/* function to get the intersection point of two linked
lists head1 and head2 */
Node* getIntesectionNode(Node* head1, Node* head2)
{
	while (head2) {
		Node* temp = head1;
		while (temp) {
			// if both Nodes are same
			if (temp == head2)
				return head2;
			temp = temp->next;
		}
		head2 = head2->next;
	}
	// intersection is not present between the lists
	return NULL;
}

// Driver Code
int main()
{
	/*
		Create two linked lists

		1st 3->6->9->15->30
		2nd 10->15->30

		15 is the intersection point
	*/

	Node* newNode;

	// Addition of new nodes
	Node* head1 = (Node*)malloc(sizeof(Node));
	head1->data = 10;

	Node* head2 = (Node*)malloc(sizeof(Node));
	head2->data = 3;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = 6;
	head2->next = newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	Node* intersectionPoint
		= getIntesectionNode(head1, head2);

	if (!intersectionPoint)
		printf(" No Intersection Point \n");
	else
		printf("Intersection Point: %d\n",
			intersectionPoint->data);
}



