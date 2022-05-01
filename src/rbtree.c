#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  return p;  
}

void left_rotate(rbtree *t, node_t * target){
  node_t *new_root = target ->right;
  target ->right = new_root->left;

  if (new_root->left != NULL)
    new_root->left->parent = target;
  new_root->parent = target->parent;

  if (target->parent == NULL){
    t->root = new_root;
  }else if (target == target->parent->right){
    target->parent->left = new_root;
  }else{
    target->parent->right = new_root;
  }
  
  new_root->left = target;
  target->parent = new_root;
}

void right_rotate(rbtree *t, node_t *target){
  node_t *new_root = target ->left;
  target ->left = new_root->right;

  if (new_root->right != NULL)
    new_root->right->parent = target;
  new_root->parent = target->parent;

  if (target->parent == NULL){
    t->root = new_root;
  }else if (target == target->parent->left){
    target->parent->right = new_root;
  }else{
    target->parent->left = new_root;
  }
  
  new_root->right = target;
  target->parent = new_root;
}

void rb_insert_fixup(rbtree *t, node_t * target){
  while (target->parent != NULL && target->parent->color == RBTREE_RED){
    if (target->parent == target->parent->parent->left){
      node_t * temp = target->parent->parent->right;
      if (temp->color == RBTREE_RED){
        if (target->parent != NULL)
          target->parent->color = RBTREE_BLACK;
        if(temp  != NULL)
          temp ->color = RBTREE_BLACK;
        target = target->parent->parent;
      }else if(target == target->parent->right){
        target = target->parent;
        left_rotate(t, target);
        // 부모의 색상 변경
        target->parent->color = RBTREE_BLACK;
        // 조부모의 색상 변경
        target->parent->parent->color = RBTREE_RED;
      }
    }else{
      node_t * temp = target->parent->parent->left;
      if (temp->color == RBTREE_RED){
        if(target->parent != NULL)
          target->parent->color = RBTREE_BLACK;
        if(temp != NULL)
          temp ->color = RBTREE_BLACK;
        target = target->parent->parent;
      }else if(target == target->parent->left){
        target = target->parent;
        left_rotate(t, target);
        // 부모의 색상 변경
        if(target->parent != NULL)
        target->parent->color = RBTREE_BLACK;
        // 조부모의 색상 변경
        if(target->parent->parent->color != NULL)
          target->parent->parent->color = RBTREE_RED;
      }
    }
  }
  t->root->color = RBTREE_BLACK;
  
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  node_t *new_node = (node_t *)calloc(1, sizeof(node_t));
  new_node->key = key;

  node_t *curr_node = t->root;
  node_t * parent = NULL;
  
  while (curr_node != NULL){
    parent = curr_node;
    curr_node = (curr_node->key > key) ? curr_node->left :  curr_node->right;
  }

  new_node->parent = parent;

  if (parent == NULL){
    t->root = new_node;
    new_node->color = RBTREE_BLACK;
    return t->root;
  }else if (key < parent->key){
    parent->left = new_node;
  }else{
    parent->right = new_node;
  }  
  new_node->color = RBTREE_RED;

  rb_insert_fixup(t, new_node);
  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
