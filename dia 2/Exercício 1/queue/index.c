// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
// Time Complexity: O(1);
struct Queue* createQueue(unsigned capacity) {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(
		queue->capacity * sizeof(int));
	return queue;
}

// Queue is full when size becomes
// equal to the capacity
// Time Complexity: O(1);
int isFull(struct Queue* queue) {
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
// Time Complexity: O(1);
int isEmpty(struct Queue* queue) {
	return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
// Time Complexity: O(1);
void enqueue(struct Queue* queue, int item) {
	if (isFull(queue)) return;
  // If queue is empty, rear is it's start
  if (isEmpty(queue)) {
    queue->rear = 0;
  } else {
	  queue->rear = queue->rear + 1;
  } 
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
// Time Complexity: O(1);
int dequeue(struct Queue* queue) {
	if (isEmpty(queue)) return INT_MIN;
	if (isFull(queue)) {
    queue->front = 0;
  } else {
	  queue->front = queue->front + 1;
  } 
	int item = queue->array[queue->front];
	queue->size = queue->size - 1;
	return item;
}

// Function to get front of queue
int getFront(struct Queue* queue) {
	if (isEmpty(queue)) return INT_MIN;
	return queue->array[queue->front + 1];
}

// Function to get rear of queue
int getRear(struct Queue* queue) {
	if (isEmpty(queue)) return INT_MIN;
	return queue->array[queue->rear];
}

// Driver program to test above functions./
int main()
{
	struct Queue* queue = createQueue(8);

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	printf("\n%d dequeued from queue\n\n", dequeue(queue));
	printf("%d dequeued from queue\n\n", dequeue(queue));
	printf("%d dequeued from queue\n\n", dequeue(queue));
	printf("%d dequeued from queue\n\n", dequeue(queue));

	printf("Front item is %d\n", getFront(queue));
	printf("Rear item is %d\n", getRear(queue));
	printf("Size item is %d\n", queue->size);

	return 0;
}
