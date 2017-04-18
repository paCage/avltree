/*
 * avl_rotate_ccw_tests.c
 */


#include <cgreen/cgreen.h>
#include "avltree_types.h"
#include "new_avltree.h"
#include "avl_rotate_ccw.h"


avlnode_t nodes[3];


Describe(avl_rotate_ccw);


BeforeEach(avl_rotate_ccw)
{
  /*
   * Test case:
   *
   *     +---+                               +---+
   *     | 0 |                               | 1 |
   *     +---+                               +---+
   *          \                             /
   *           +---+    ccw rotate     +---+
   *           | 1 |   ============>   | 0 |
   *           +---+                   +---+
   *          /                             \
   *     +---+                               +---+
   *     | 2 |                               | 2 |
   *     +---+                               +---+
   */

  for(int i = 0; i < 3; i++)
    {
      nodes[i].iKey = i;
      nodes[i].left = NULL;
      nodes[i].right = NULL;
    }

  nodes[0].right = &nodes[1];
  nodes[0].right->left = &nodes[2];
}


AfterEach(avl_rotate_ccw) {}


Ensure(avl_rotate_ccw, works_properly)
{
  avlnode_t* rotated_node = avl_rotate_ccw(&nodes[0]);

  assert_that(rotated_node->iKey, is_equal_to(1));
  assert_that(rotated_node->right, is_null);
  assert_that(rotated_node->left, is_non_null);

  assert_that(rotated_node->left->iKey, is_equal_to(0));
  assert_that(rotated_node->left->left, is_null);
  assert_that(rotated_node->left->right, is_non_null);

  assert_that(rotated_node->left->right->iKey, is_equal_to(2));
  assert_that(rotated_node->left->right->right, is_null);
  assert_that(rotated_node->left->right->left, is_null);
}
