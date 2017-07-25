MODULE_NAME := avltree

_FILES := new_avltree \
          avl_rotate_cw \
          avl_rotate_ccw \
          avl_push

_TESTS := new_avltree_tests \
          avl_rotate_cw_tests \
          avl_rotate_ccw_tests \
          avl_push_tests

_DEPS :=

include ./Makefile.paCage/Makefile
