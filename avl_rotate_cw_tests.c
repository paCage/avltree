/*
 * avl_rotate_cw_tests.c
 */


#include <cgreen/cgreen.h>
#include "avltree_types.h"
#include "new_avltree.h"
#include "avl_rotate_cw.h"


avlnode_t nodes[3];


Describe(avl_rotate_cw);


BeforeEach(avl_rotate_cw)
{
  /*
   * Test case:
   *
   *           +---+                   +---+
   *           | 0 |                   | 1 |
   *           +---+                   +---+
   *          /                             \
   *     +---+           cw rotate           +---+
   *     | 1 |          ===========>         | 0 |
   *     +---+                               +---+
   *          \                             /
   *           +---+                   +---+
   *           | 2 |                   | 2 |
   *           +---+                   +---+
   */

  for(int i = 0; i < 3; i++)
    {
      nodes[i].iKey = i;
      nodes[i].left = NULL;
      nodes[i].right = NULL;
    }

  nodes[0].left = &nodes[1];
  nodes[0].left->right = &nodes[2];
}


AfterEach(avl_rotate_cw) {}


Ensure(avl_rotate_cw, works_properly)
{
  avlnode_t* rotated_node = avl_rotate_cw(&nodes[0]);

  assert_that(rotated_node->iKey, is_equal_to(1));
  assert_that(rotated_node->left, is_null);
  assert_that(rotated_node->right, is_non_null);

  assert_that(rotated_node->right->iKey, is_equal_to(0));
  assert_that(rotated_node->right->right, is_null);
  assert_that(rotated_node->right->left, is_non_null);

  assert_that(rotated_node->right->left->iKey, is_equal_to(2));
  assert_that(rotated_node->right->left->right, is_null);
  assert_that(rotated_node->right->left->left, is_null);
}
