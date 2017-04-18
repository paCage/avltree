#ifndef _AVLTREE_TYPES_H_
#define _AVLTREE_TYPES_H_


#define AVL_INT 0
#define AVL_FLOAT 1
#define AVL_DOUBLE 2


typedef struct _avlnode_t
{
  struct _avlnode_t *left, *right;
  union
  {
    int iKey;
    float fKey;
    double dKey;
  };
  int height;
  void* data;
} avlnode_t;


typedef struct _avltree_t
{
  avlnode_t* root;
  int keyType;
  int len;
} avltree_t;


#endif /* _AVLTREE_TYPES_H_ */
