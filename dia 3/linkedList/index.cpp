#include <bits/stdc++.h>
using namespace std;

class Node {
  private:
    int data;
    Node *next;
  public:
    Node(int data) {
      this->data = data;
      this->next = NULL;
    }

    int getData() {
      return data;
    }

    Node* getNext() {
      return next;
    }

    void setData(int data) {
      this->data = data;
    } 

    void setNext(Node *next) {
      this->next = next;
    }
};

class LinkedList {
  private:
    Node *head = NULL;
  
  public:
    int size = 0;
    LinkedList(int data){
      Node* newHead = new Node(data);
      this->head = newHead;
      this->size++;
    }

    LinkedList() {};

    void push(int newData) {
    Node* newNode = new Node(newData);
    newNode->setNext(head);
    head = newNode;
    this->size++;
    }
  
    void insertAt(unsigned position, int newData) { 
      Node *newNode = new Node(newData), *temp = this->head, *prev;
      int i = 0;
      if(position == 0) {
        this->push(newData);
        return;
      }
      while (i != position && temp != NULL) {
        i++;
        prev = temp;
        temp = temp->getNext();
      } 
      if (i != position) {
        cout << "It's not possible to insert at this position.\n";
        return;
      }
      prev->setNext(newNode);
      newNode->setNext(temp);
      this->size++;
      return;
    }
    
    void append(int newData) {
      Node* newNode = new Node(newData);
      Node* temp = head;

      if(temp == NULL) {
        this->head = newNode;
        return;
      }
      
      while(temp->getNext() != NULL) {
        temp = temp->getNext();
      }

      temp->setNext(newNode);
      this->size++;
      return;
    }
    
    void deleteNode(int key) {
      Node *temp = head, *prev;
      if(temp != NULL && temp->getData() == key) {
        this->head = temp->getNext();
        free(temp);
        this->size--;
        return;
      }

      while(temp != NULL && temp->getData() != key) {
        prev = temp;
        temp = temp->getNext();
      }
      
      if(temp == NULL) return;

      temp->setNext(prev->getNext());
      free(temp);
      this->size--;
      return;
    }

    void deleteNodeAtPosition(int position) {
      Node *temp = this->head, *prev;
      int i = 0;
      if(temp != NULL && i == position) {
        this->head = temp->getNext();
        free(temp);
        this->size--;
        return;
      }

      while(temp != NULL && i != position) {
        prev = temp;
        temp = temp->getNext();
        i++;
      }
      
      if(temp == NULL) return;

      temp->setNext(prev->getNext());
      free(temp);
      this->size--;
      return;
    }

    Node* removeFirst() {
      Node *temp = this->head;
      if (temp == NULL) return NULL;
      this->head = temp->getNext();
      this->size--;
      return temp;
    }

    Node* removeLast() {
      Node *temp = this->head, *prev;
      while(temp->getNext() != NULL) {
        prev = temp;
        temp = temp->getNext();
      }
      prev->setNext(NULL);
      this->size--;
      return temp;
    }

    Node* getFirst() {
      if (this->head == NULL) return NULL;
      return this->head;
    }

    Node* getLast() {
      Node *temp = this->head;
      while(temp->getNext() != NULL) {
        temp = temp->getNext();
      }
      return temp;
    }

    void traversal() {
      Node* temp = this->head;
      cout << "The list goes:\n";
      while(temp != NULL) {
        cout << temp->getData() << "\n" ;
        temp = temp->getNext();
      }
    }
};

class Queue {
  private: 
    LinkedList *queue = NULL;

  public:
    Queue(int data) {
      LinkedList *newList = new LinkedList(data);
      this->queue = newList;
    }

    Queue() {
      LinkedList *newList = new LinkedList;
      this->queue = newList;
    }

    void enqueue(int data) {
      this->queue->append(data);
    }

    Node* dequeue() {
      return this->queue->removeFirst();
    }

    Node* getFirst() {
      return this->queue->getFirst();
    }

    Node* getLast() {
      return this->queue->getLast();
    }

    void traversal () {
      this->queue->traversal();
    }
};

class Stack {
  private:
    LinkedList *stack = NULL;

  public:
    Stack(int data) {
      LinkedList *newList = new LinkedList(data);
      this->stack = newList;
    }

    Stack() {
      LinkedList *newList = new LinkedList;
      this->stack = newList;
    }
    
    void append(int data) {
      this->stack->append(data);
    }

    Node* pop() {
      return this->stack->removeLast();
    }

    Node* peek() {
      return this->stack->getLast();
    }

    void traversal() {
      this->stack->traversal();
    }
};

int main () {
  LinkedList *list = new LinkedList;
  Queue *queue = new Queue;
  Stack *stack = new Stack;

  stack->append(1);
  stack->append(2);
  stack->append(3);
  stack->append(4);
  stack->append(5);
  stack->traversal();
  stack->pop();
  stack->pop();
  stack->traversal();
  cout << "\nPeek:" << stack->peek()->getData();
}

// This code is contributed by rathbhupendra
