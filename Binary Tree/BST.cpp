#include <iostream>
using namespace std;

class node {
public:
  int data;
  node* left;
  node* right;

  node(int d) {
    this -> data = d;
    left = NULL;
    right = NULL;
  }
};

node* insertInBST(node* root, int d) {
  if(root == NULL) {
    return new node(d);
  }

  if(d <= (root -> data)) {
    root -> left = insertInBST(root -> left, d);
  }
  else {
    root -> right = insertInBST(root -> right, d);
  }
}

node* buildBST() {
  //Read a list of numbers till -1
  int d;
  cin>>d;

  node* root = NULL;
  while(d != -1) {
    root = insertInBST(root, d);
    cin>>d;
  }
  return root;
}

void inorder(node*root) {
  if(root == NULL) {
    return;
  }
  inorder(root -> left);
  cout<<root -> data<<" ";
  inorder(root -> right);
}

int main() {
  node* root = buildBST();
  inorder(root);

  return 0;
}
