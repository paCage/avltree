/*
 * avl_rotate_ccw.c
 * tests_file: avl_rotate_ccw_tests.c
 *
 * Rotating a node configuration anticlockwise
 *
 * @param: node: Pointer to an allocated node
 *               Note that the left child of the node must be non_null
 *
 * @return: replaced node
 */


#include <stdlib.h>
#include "./avl_rotate_ccw.h"


#define max(a, b) (a > b ? a : b)
#define height(node) (node == NULL ? 0 : node->height)


avlnode_t* avl_rotate_ccw(avlnode_t* x)
{
  avlnode_t* y = x->right;
  avlnode_t* T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}
