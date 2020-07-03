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

  if(d < root -> data) {
    root -> left = insertInBST(root -> left, d);
  }
  else {
    root -> right = insertInBST(root -> right, d);
  }

  return root;
}

node* buildBST() {
  int d;
  cin>>d;

  node* root = NULL;
  while(d != -1) {
    root = insertInBST(root, d);
    cin>>d;
  }
  return root;
}

// void inorder(node* root) {
//   if(root == NULL) {
//     return;
//   }
//
//   inorder(root -> left);
//   cout<<root -> data<<" ";
//   inorder(root -> right);
// }

bool searchBST(node* root, int d) {
  if(root == NULL) {
    return false;
  }
  if(root -> data == d) {
    return true;
  }
  
  if(root -> data >= d) {
    return searchBST(root -> left, d);
  }
  else {
    return searchBST(root -> right, d);
  }
}

int main() {
  node* root = buildBST();
  int d;
  cin>>d;
  cout<<searchBST(root, d);

  return 0;
}
