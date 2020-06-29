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

node* preOrder() {
  int d;
  cin>>d;

  if(d == -1) {
    return NULL;
  }

  node* root = new node(d);
  root -> left = preOrder();
  root -> right = preOrder();

  return root;
}

int countNodes(node* root) {
  if(root == NULL) {
    return 0;
  }
  int count = 1 + countNodes(root -> left) + countNodes(root -> right);
  return count;
}

void print(node* root) {
  if(root == NULL) {
    return;
  }

  print(root -> left);
  cout<<root -> data<<" ";
  print(root -> right);
}

int main() {
  node* root = preOrder();
  cout<<countNodes(root);
  return 0;
}
