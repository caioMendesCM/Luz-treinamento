// A complete working C program to demonstrate all insertion methods
// on Linked List
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
int data;
struct Node *next;
};

// INSERTION FUNCTIONS

// add a new data at the start of a given list.
// Time complexity: O(1).
void push(struct Node** head_ref, int new_data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

// add a new data after a giver Node.
// Time complexity: O(1).
void insertAfter(struct Node* prev_node, int new_data) {
	if (prev_node == NULL) {
    printf("the given previous node cannot be NULL");
    return;
	}

	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = prev_node->next;

	prev_node->next = new_node;
}

// add a new data at the end of a given list
// Time complexity: O(n)
void append(struct Node** head_ref, int new_data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref;

	new_node->data = new_data;

	new_node->next = NULL;

	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}

  // search for the last node of a list given it's head 
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return;
}

// DELETING FUNCTIONS

// Delete a Node given a key.
// Time complexity: O(n). 
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;
  
  // If head node itself holds the key to be deleted
  if (temp != NULL && temp->data == key) {
      *head_ref = temp->next; // Changed head
      free(temp); // free old head
      return;
  }
 
  // Search for the key to be deleted, keep track of the
  // previous node as we need to change 'prev->next'
  while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
  }
  
  // If key was not present in linked list
  if (temp == NULL) return;
 
  // Unlink the node from linked list
  prev->next = temp->next;
 
  free(temp); // Free memory
}

// Delete a Node given a position.
// Time complexity: O(n).
void deleteNodeAtPosition(struct Node** head_ref, int position) {
  struct Node *temp = *head_ref, *prev;

  // If head node itself is at the position to be deleted
  int i = 0;
  if (temp != NULL && i == position) {
      *head_ref = temp->next; // Changed head
      free(temp); // free old head
      return;
  }

  // Search for the key to be deleted, keep track of the
  // previous node as we need to change 'prev->next'
  while (temp != NULL && i != position) {
      prev = temp;
      temp = temp->next;
      i++;
  }

  // If the list ends before i reach the position
  if (temp == NULL) return;

  // Unlink the node from linked list
  prev->next = temp->next;

  free(temp); // Free memory
}

//CHANGING FUNCTIONS

// Change a node value given a position.
// Time complexity: O(n).
void changeNode(struct Node** head_ref, int position, int new_data) {
  struct Node *node = *head_ref;
  int i = 0;
  while (node != NULL && i != position) {
    node = node->next;
    i++;
  }

  node->data = new_data;
}

// READING FUNCTIONS

// Return the value of a node at a given position
// Time complexity: O(n).
int readNode(struct Node** head_ref, int position) {
  if (head_ref == NULL) {
    printf("the given previous node cannot be NULL");
	}
  struct Node *node = *head_ref;

  int i = 0;
  while (node != NULL && i != position) {
    node = node->next;
    i++;
  }

  return node->data;
}

bool searchNode(struct Node** head_ref, int key) {
  struct Node* node = *head_ref;

  while (node != NULL) {
    if (node->data == key) return true;
    node = node->next;
  }
  return false;
}

// UTILITIES FUNCTIONS

// This function prints contents of linked list starting from head
void printList(struct Node *node) {
  // Print a node and goes to the next until the list ends
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main()
{
  struct Node* head = NULL;
 
  append(&head, 6);

  push(&head, 7);
 
  push(&head, 1);
 
  append(&head, 4);
 
  insertAfter(head->next, 8);
  
  // changeNode(&head, 2, 10);
  int valor = readNode(&head, 2);
  printf("Valor: %d\n", valor);

  printf("\nCreated Linked list is: ");
  printList(head);
 
  return 0;
}