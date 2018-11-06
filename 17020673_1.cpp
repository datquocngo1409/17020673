#include <iostream>
using namespace std;

struct Node{
 int val;
 Node *left, *right;
};

void add_node(Node* &root, int x){
 if (root == NULL){
  root = new Node;
  root->val = x;
  root->left = root->right = NULL;
 }
 else {
  if (x < root->val) add_node(root->left, x);
  else if (x > root->val) add_node(root->right, x);
 }
}

  /* Function to traverse binary tree without recursion and
  without stack */
  void lnr(Node *root)
  {
   Node*pre;
   Node*current=root;
   while (current)
   {
    if (!current->left)
    {
     cout << current->val << " ";
     current = current->right;
    }
    else
    {
     pre = current->left;
     while (pre->right&&pre->right != current)
     {
      pre = pre->right;
     }
     if (!pre->right)
     {
      pre->right = current;
      current = current->left;
     }
     else
     {
      cout << current->val << " ";
      pre->right = NULL;
      current = current->right;
     }
    }
   }
  }


int height(Node* t){
 if (t){
  int l = height(t->left), r = height(t->right);
  return (l < r ? r : l) + 1;
 }
 return 0;
}
int main()
{

 Node* root = NULL;
 cout << "Enter the tree: (Enter 0 to Exit!)" << endl;
 while (true){
  int x; cin >> x;
  if (x == 0) break;
  add_node(root, x);
 }
 cout << "Tree LNR: " << endl;
 lnr(root);

 return 0;
}

