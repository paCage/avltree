/*
 * new_avltree.c
 * tests_file: new_avltree_tests.c
 *
 * avltree constructor
 *
 * @param: avl: Pointer to an allocated space for an AVL tree
 * @param: key_type: Type of the avltree key (e.g. AVL_INT, AVL_FLOAT)
 *
 * @return: void
 */


#include <stdlib.h>
#include "./new_avltree.h"


void new_avltree(avltree_t *avl, int key_type)
{
  avl->root = NULL;
  avl->keyType = key_type;
  avl->len = 0;
}
