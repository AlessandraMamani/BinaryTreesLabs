#include <stdio.h>
#include "tree_algorithms.h"

/*
 * Este archivo contiene los ejercicios de la practica.
 *
 * Complete cada funcion sin modificar su firma.
 * Las implementaciones iniciales permiten compilar el proyecto, pero
 * NO resuelven los ejercicios.
 */

size_t treeSize(const Node *root) {
  if(root == NULL) return 0;
  return 1 + treeSize(root->left) + treeSize(root->right);
}

int maxDepth(const Node *root) {
  if(root == NULL) return 0;
  size_t right = maxDepth(root->right);
  size_t left = maxDepth(root->left);
  return 1 + ((right > left) ? right : left);
}

int minValue(const Node *root) {
  if(root == NULL) return 0;
  while(root->left != NULL) 
    root = root->left;
  return root->data;
}

void printTree(const Node *root) {
  if(root == NULL) return;
  printTree(root->left);
  printf("%d",root->data);
  printTree(root->right);
}

void printPostorder(const Node *root) {
  if(root == NULL) return;
  printPostorder(root->left);
  printPostorder(root->right);
  printf("%d",root->data);
}

int hasPathSum(const Node *root, int sum) {
  if(root == NULL) return 0;
  if(root->left == NULL && root->right == NULL)
    return (root->data == sum);
  return hasPathSum(root->left, sum - root->data) || 
          hasPathSum(root->right, sum- root->data);
}

void printPaths(const Node *root) {
  int path[1000];
  printPathRecur(root, path);
}

void printArray(int path[], int pathLen){
  for(int i = 0; i < pathLen; ++i){
    printf("%d ",path[i]);
  }
}

static void printPathRecur(const Node* root, int path[], int pathLen){
  if(root == NULL) return;
  path[pathLen] = root->data;
  if(root->left == NULL && root->right == NULL){ 
    printArray(path, pathLen);
    return;
  }
  printPathRecur(root->left, path, pathLen + 1);
  printPathRecur(root->right, path, pathLen + 1);
}

void mirror(Node *root) {
  if(root == NULL) return;

  struct Node* aux = root->left;
  root->left = root->right;
  root->right = aux;

  mirror(root->left);
  mirror(root->right);
}

int sameTree(const Node *a, const Node *b) {
  if (a == NULL && b == NULL) return 1;
  if (a == NULL || b == NULL) return 0;
  if (a->data != b->data) return 0;
  return sameTree(a->left, b->left) && sameTree(a->right, b->right);
}

int isBST(const Node *root) {
  int prev = -1;
  return isBSTRec(root, &prev);
}

int isBSTRec(const Node* root, int* prev){
  if (root == NULL) return 1;
  if (!isBSTRec(root->left, prev)) return 0;
  if (root->data <= *prev) return 0;
  *prev = root->data;
  if (!isBSTRec(root->right, prev)) return 0;
  return 1;
}

