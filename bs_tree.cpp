
#include "bs_tree.h"
#include <list>
#include <iostream>
#include <string.h>
#include<bits/stdc++.h>

using namespace std;

/*
 * constructor/destructor
 */
bs_tree::bs_tree()
{ /*<<<*/
    T_root = NULL;
}
/*>>>*/

bs_tree::~bs_tree()
{ /*<<<*/
/*
 * delete all other allocated nodes
 */
  remove_all(T_root);
} /*>>>*/

void bs_tree::insert(int key)
{ /*<<<*/
/*
 * wrapper around insert
 * -> inserts node
 */
  bs_tree_node* z;

  z = new bs_tree_node;
  z->key = key;

  insert(z);
} /*>>>*/

void bs_tree::insert(bs_tree_node* z)
{ /*<<<*/
/*
 * binary tree type insert
 * -> search position, insert new node
 * -> fix properties after insert
 */
  bs_tree_node* x;
  bs_tree_node* y;
  y = NULL;
  x = T_root;
  while (x != NULL)
    {
      y = x;
      if(z->key == x->key) {
        x->count++;
        return;
      }
      if (z->key < x->key){
        x = x->left;
      }  else {
        x = x->right;
}
    }

  z->p = y;
  if (y == NULL) {
    T_root = z;
    z->count = 1;
    newSize++;
  }

  else
    {
      if (z->key < y->key){
        y->left = z;
      }
      else {
        y->right = z;
      }
      z->count = 1;
      newSize++;
    }
}
int bs_tree::convert(int* input_array, int n) {
  new_input_array = new int[newSize];
  inorder_output();
  memset(input_array, 0, newSize);
  for (int i = 0; i < newSize; i++) {
    input_array[i] = new_input_array[i];
}
  delete[] new_input_array;
  bs_tree_i_info.duplicates = n - newSize ;
  return newSize;
}
void bs_tree::inorder_output(bs_tree_node* x, int level)
{ /*<<<*/
/*
 * in order walk through binary tree
 * -> see book or slides
 */

  if (x != NULL)
    {
      inorder_output(x->left, level+1);
      // cout << "(" << x->key << "," << level <<",count:"<<x->count<< ")" << endl;
      new_input_array[newCount] = x->key;
      newCount++;
      inorder_output(x->right, level+1);
    }

} /*>>>*/

void bs_tree::output(bs_tree_node* x, int r_level)
{ /*<<<*/
/*
 * some structured output
 */
  list< pair<bs_tree_node*,int> > l_nodes;
  pair<bs_tree_node*,int> c_node;
  int c_level;

  c_level = r_level;
  l_nodes.insert(l_nodes.end(), pair<bs_tree_node*,int>(x, r_level));

  while (!l_nodes.empty())
    {
      c_node = *(l_nodes.begin());

      if (c_level < c_node.second)
	{
	  cout << endl;
	  c_level = c_node.second;
	}
      cout << "(" << c_node.first->key<< ",duplicate count:"<<c_node.first->count ;

      if (c_node.first->p == NULL)
	cout << ",ROOT) ";
      else
        cout << ",P:" << c_node.first->p->key <<") ";

      if (c_node.first->left != NULL)
	l_nodes.insert(l_nodes.end(), pair<bs_tree_node*,int>(c_node.first->left,
							      c_node.second+1));
      if (c_node.first->right != NULL)
	l_nodes.insert(l_nodes.end(), pair<bs_tree_node*,int>(c_node.first->right,
							      c_node.second+1));
      l_nodes.erase(l_nodes.begin());
    }

  cout << endl;
} /*>>>*/


void bs_tree:: reset(){
  memset(&bsTreeNode, 0, sizeof(bsTreeNode));
  memset(&bs_tree_i_info, 0, sizeof(bs_tree_i_info));
}

void bs_tree::remove_all(bs_tree_node* x)
{ /*<<<*/
/*
 * recursively remove all tree elements
 */
 if(x!= NULL) {
  remove_all(x->left);
  remove_all(x->right);
  delete x;
}
} /*>>>*/
