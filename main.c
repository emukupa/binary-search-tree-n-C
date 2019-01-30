#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *new_node(int val)
{
  Node *a_node = (Node *)malloc(sizeof(Node));
  a_node->data = val;
  a_node->left = NULL;
  a_node->right = NULL;
  return a_node;
}

Node *insert(Node *node, int val)
{
  if (node == NULL)
  {
    return new_node(val);
  }

  if (val <= node->data)
  {
    node->left = insert(node->left, val);
  }
  else
  {
    node->right = insert(node->right, val);
  }

  return node;
}

int contains(Node *node, int val)
{
  return 0;
}

void printInOrder(Node *root)
{
  if (root != NULL)
  {
    printInOrder(root->left);
    printf("%d\n", root->data);
    printInOrder(root->right);
  }
}

void printPreOrder(Node *root)
{
  if (root != NULL)
  {
    printf("%d\n", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

void printPostOrder(Node *root)
{
  if (root != NULL)
  {
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d\n", root->data);
  }
}

int main(void)
{
  Node *root = NULL;

  root = insert(root, 100);
  root = insert(root, 60);
  root = insert(root, 200);
  root = insert(root, 150);
  root = insert(root, 250);
  root = insert(root, 40);
  root = insert(root, 80);

  printf("PrintInorder\n");
  printInOrder(root);

  printf("PrintPreorder\n");
  printPreOrder(root);

  printf("PrintPostorder\n");
  printPostOrder(root);

  return 0;
}