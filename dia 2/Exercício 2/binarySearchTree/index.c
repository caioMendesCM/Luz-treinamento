// C program to demonstrate insert
// operation in binary
// search tree.
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key; 
  int size;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
  temp->size = 1;
	temp->left = temp->right = NULL;
	return temp;
}

void preOrder(struct node* root) {
	if (root != NULL) {
		printf("%d \n", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

// A utility function to do inorder traversal of BST
void inOrder(struct node* root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("%d \n", root->key);
		inOrder(root->right);
	}
}

void postOrder(struct node* root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d \n", root->key);
	}
}

/* A utility function to insert
a new node with given key in
* BST */
struct node* insert(struct node* node, int key) {
	if (node == NULL) return newNode(key);

	if (key < node->key) {
    node->left = insert(node->left, key);
  } else if (key > node->key) {
		node->right = insert(node->right, key);
  }

  node->size += 1;
	/* return the (unchanged) node pointer */
	return node;
}

// C function to search a given key in a given BST
struct node* search(struct node* root, int key) {
  // Base Cases: root is null or key is present at root
  if (root == NULL || root->key == key) return root;
  
  // Key is greater than root's key
  if (key > root->key) return search(root->right, key);
 
  // Key is smaller than root's key
  return search(root->left, key);
}

struct node* minValueNode(struct node* node) {
  struct node* current = node;

  /* loop down to find the leftmost leaf */
  while (current && current->left != NULL) {
    current = current->left;
  }

  return current;
}
 
/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
struct node* deleteNode(struct node* root, int key)
{
  // base case
  if (root == NULL) return root;
 
  if (key < root->key) {
    root->left = deleteNode(root->left, key);

  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
 
  } else {
    // node with only one child or no child
    if (root->left == NULL) {
      struct node* temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct node* temp = root->left;
      free(root);
      return temp;
    }

    // node with two children:
    // Get the inorder successor
    // (smallest in the right subtree)
    struct node* temp = minValueNode(root->right);
 
    // Copy the inorder
    // successor's content to this node
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  root->size -= 1;
  return root;
}

// Driver Code
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct node* root = NULL;
	root = insert(root, 50);
  printf("innitial size: %d\n", root->size);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

  printf("pos inserts size: %d\n", root->size);

  deleteNode(root, 40);
  printf("pos delete size: %d\n", root->size);


  printf("preorder:\n");
  preOrder(root);
  printf("\n\n");
  printf("inorder:\n");
	inOrder(root);
  printf("\n\n");
  printf("postorder:\n");
  postOrder(root);
  printf("\n\n");

	return 0;
}
