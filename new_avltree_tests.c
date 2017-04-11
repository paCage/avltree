/*
 * new_avltree_tests.c
 */


#include <cgreen/cgreen.h>
#include "avltree_types.h"
#include "new_avltree.h"


Describe(new_avltree);
BeforeEach(new_avltree) {}
AfterEach(new_avltree) {}


Ensure(new_avltree, constructor_works_properly)
{
  avltree_t avl;
  new_avltree(&avl, AVL_INT);

  assert_that(avl.root, is_null);
  assert_that(avl.keyType, is_equal_to(AVL_INT));
  assert_that(avl.len, is_equal_to(0));
}
