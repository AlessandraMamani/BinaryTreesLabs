#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree_algorithms.h"

static Node *buildExample(void) {
  const int values[] = {5, 3, 9, 1, 4, 6};
  const size_t n = sizeof values / sizeof values[0];

  Node *root = NULL;

  for(size_t i = 0; i < n; ++i) {
    Node *newRoot = insert(root, values[i]);

    if(newRoot == NULL) {
      freeTree(root);
      return NULL;
    }

    root = newRoot;
  }

  return root;
}

int main(void) {
  Node *root = buildExample();

  if(root == NULL) {
    fprintf(stderr, "No se pudo construir el arbol.\n");
    return EXIT_FAILURE;
  }

  /*
   * Active estas pruebas a medida que implemente las funciones.
   *
   * printf("size = %zu\n", treeSize(root));
   * printf("maxDepth = %d\n", maxDepth(root));
   * printf("minValue = %d\n", minValue(root));
   *
   * printf("inorder: ");
   * printTree(root);
   * printf("\n");
   *
   * printf("postorder: ");
   * printPostorder(root);
   * printf("\n");
   */

  freeTree(root);
  return EXIT_SUCCESS;
}
