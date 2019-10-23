#ifndef __BS_TREE_H__
#define __BS_TREE_H__
#include <stdlib.h>

struct bs_tree_node
{
  int key;
  int count;
  bs_tree_node*	left;
  bs_tree_node*	right;
  bs_tree_node*	p;
};
struct bs_info {
  int duplicates= 0 ;
};
class bs_tree
{
  protected:
    bs_tree_node*	T_root;
    int newSize = 0;
    int newCount =0;
    int* new_input_array;

  public:
    bs_tree();
    ~bs_tree();
    bs_info bs_tree_i_info;
    bs_tree_node bsTreeNode;

    void insert(int*, int);
    void insert(int);
    int convert(int*, int);
    void reset();
    void inorder_output()
      { inorder_output(T_root, 1); }
    void output()
      { output(T_root, 1); }

  protected:
    void insert(bs_tree_node*);

    void remove_all(bs_tree_node*);

    void inorder_output(bs_tree_node*, int);
    void output(bs_tree_node*, int);
    //int convert(int*);
};

#endif
