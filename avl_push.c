/*
 * avl_push.c
 * tests_file: avl_push_tests.c
 *
 * avltree constructor
 *
 * @param: avl: Pointer to an allocated space for an AVL tree
 * @param: node: Pointer to an allocated (and filled) node
 *
 * @return: void
 */


#include <stdio.h>
#include <stdlib.h>
#include "avltree_types.h"
#include "avl_rotate_cw.h"
#include "avl_rotate_ccw.h"
#include "avl_push.h"


static avlnode_t* push(avltree_t*, avlnode_t*, avlnode_t*);
static int compare_keys(avltree_t*, avlnode_t*, avlnode_t*);


#define max(a, b) (a > b ? a : b)
#define height(node) (node == NULL ? 0 : node->height)

#define get_balance(node) \
  (node == NULL ? 0 : height(node->left) - height(node->right))

#define generic_key_comparison(type_t, n1, n2)                  \
  (                                                             \
   (*(type_t*)(char*)&n1->iKey > *(type_t*)(char*)&n2->iKey)    \
   ? AVL_GREATER_THAN                                           \
   : ((*(type_t*)(char*)&n1->iKey < *(type_t*)(char*)&n2->iKey) \
      ? AVL_LESS_THAN                                           \
      : AVL_EQUALS))

#define AVL_LESS_THAN -1
#define AVL_GREATER_THAN 1
#define AVL_EQUALS 0


void avl_push(avltree_t* avl, avlnode_t* node)
{
  if(node == NULL)
    return;

  avl->len++; // Increment the length of the tree
  avl->root = push(avl, avl->root, node);
}


static avlnode_t* push(avltree_t* avl, avlnode_t* node, avlnode_t* new_node)
{
  if(node == NULL)
    return new_node;

  if(compare_keys(avl, node, new_node) == AVL_GREATER_THAN)
    node->left = push(avl, node->left, new_node);
  else if(compare_keys(avl, node, new_node) == AVL_LESS_THAN)
    node->right = push(avl, node->right, new_node);
  else
    {
      /*
       * Decrement the length of the tree
       * since we found a node with the same key as the key of the new_node
       */
      avl->len--;
      return node;
    }

  node->height = max(height(node->left), height(node->right)) + 1;

  int balance = get_balance(node);

  if(balance > 1)
    {
      switch(compare_keys(avl, node, new_node))
        {
        case AVL_GREATER_THAN:
          return avl_rotate_cw(node);
        case AVL_LESS_THAN:
          node->left =  avl_rotate_ccw(node->left);
          return avl_rotate_cw(node);
        }
    }
  else if(balance < -1)
    {
      switch(compare_keys(avl, node, new_node))
        {
        case AVL_LESS_THAN:
          return avl_rotate_ccw(node);
        case AVL_GREATER_THAN:
          node->right = avl_rotate_cw(node->right);
          return avl_rotate_ccw(node);
        }
    }

  return node;
}


static int compare_keys(avltree_t* avl, avlnode_t* node, avlnode_t* new_node)
{
  switch(avl->keyType)
    {
    case AVL_INT:
      return generic_key_comparison(int, node, new_node);
    case AVL_FLOAT:
      return generic_key_comparison(float, node, new_node);
    default:
      return generic_key_comparison(double, node, new_node);
    }
}
