/*
 * avl_rotate_cw.c
 * tests_file: avl_rotate_cw_tests.c
 *
 * Rotating a node configuration clockwise
 *
 * @param: node: Pointer to an allocated node
 *               Note that the left child of the node must be non_null
 *
 * @return: replaced node
 */


#include <stdlib.h>
#include "./avl_rotate_cw.h"


#define max(a, b) (a > b ? a : b)
#define height(node) (node == NULL ? 0 : node->height)


avlnode_t* avl_rotate_cw(avlnode_t* y)
{
  avlnode_t* x = y->left;
  avlnode_t* T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}
