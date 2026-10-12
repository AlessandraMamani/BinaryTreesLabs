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
  return 1 + (right > left) ? right : left;
}

int minValue(const Node *root) {
  if(root == NULL) return 0;

}

void printTree(const Node *root) {
  (void)root;
}

void printPostorder(const Node *root) {
  (void)root;
}

int hasPathSum(const Node *root, int sum) {
  (void)root;
  (void)sum;
  return 0;
}

void printPaths(const Node *root) {
  (void)root;
}

void mirror(Node *root) {
  (void)root;
}

int sameTree(const Node *a, const Node *b) {
  (void)a;
  (void)b;
  return 0;
}

int isBST(const Node *root) {
  (void)root;
  return 0;
}
