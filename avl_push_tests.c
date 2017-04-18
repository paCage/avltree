/*
 * avl_push_tests.c
 */


#include <cgreen/cgreen.h>
#include "avltree_types.h"
#include "new_avltree.h"
#include "avl_push.h"


#define INTKEY 123
#define DOUBLEKEY 0.000000123
#define AVLLEN 119


avlnode_t* nodes;


Describe(avl_push);


BeforeEach(avl_push)
{
  nodes = malloc(AVLLEN * sizeof(*nodes));
}


AfterEach(avl_push)
{
  free(nodes);
}


Ensure(avl_push, fills_the_tree_properly)
{
  avltree_t avl;
  new_avltree(&avl, AVL_INT);

  for(int i = 0; i < AVLLEN; i++)
    {
      nodes[i].iKey = i * INTKEY;
      nodes[i].height = 0;
      nodes[i].left = NULL;
      nodes[i].right = NULL;
      avl_push(&avl, &nodes[i]);

      assert_that(avl.len, is_equal_to(i + 1));
    }
}


Ensure(avl_push, keeps_the_tree_bst)
{
  avltree_t avl;
  new_avltree(&avl, AVL_INT);

  for(int i = 0; i < AVLLEN; i++){
    nodes[i].iKey = i * INTKEY;
    nodes[i].height = 0;
    nodes[i].left = NULL;
    nodes[i].right = NULL;
    avl_push(&avl, &nodes[i]);
  }

  assert_that(avl.root, is_non_null);
  assert_that(avl.root->right, is_non_null);
  assert_that(avl.root->left, is_non_null);

  avlnode_t* node = avl.root;

  while(node){
    if(node->left != NULL && node->right != NULL)
      assert_true(node->right->iKey > node->left->iKey);

    node = node->right;
  }
}


Ensure(avl_push, prevents_from_pushing_nodes_with_same_keys)
{
  avltree_t avl;
  new_avltree(&avl, AVL_INT);

  for(int i = 0; i < AVLLEN; i++){
    nodes[i].iKey = INTKEY;
    nodes[i].height = 0;
    nodes[i].left = NULL;
    nodes[i].right = NULL;
    avl_push(&avl, &nodes[i]);
  }

  assert_that(avl.root->left, is_null);
  assert_that(avl.root->right, is_null);

  assert_that(avl.len, is_equal_to(1));
}

Ensure(avl_push, also_works_with_double_keys)
{
  avltree_t avl;
  new_avltree(&avl, AVL_DOUBLE);

  for(int i = 0; i < AVLLEN; i++){
    nodes[i].dKey = DOUBLEKEY * i;
    nodes[i].height = 0;
    nodes[i].left = NULL;
    nodes[i].right = NULL;
    avl_push(&avl, &nodes[i]);

    assert_that(avl.len, is_equal_to(i + 1));
  }

  avlnode_t* node = avl.root;

  while(node){
    if(node->left != NULL && node->right != NULL)
      assert_true(node->right->dKey > node->left->dKey);

    node = node->right;
  }
}


Ensure(avl_push, prevents_from_pushig_new_node_with_same_double_key)
{
  avltree_t avl;
  new_avltree(&avl, AVL_DOUBLE);

  int i;
  for(i = 0; i < AVLLEN; i++){
    nodes[i].dKey = DOUBLEKEY;
    nodes[i].left = NULL;
    nodes[i].right = NULL;
    avl_push(&avl, &nodes[i]);
  }

  assert_that(avl.root->left, is_null);
  assert_that(avl.root->right, is_null);

  assert_that(avl.len, is_equal_to(1));
}
