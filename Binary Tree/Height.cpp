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

int height(node* root) {
  if(root == NULL) {
    return 0;
  }

  int lh = height(root -> left);
  int rh = height(root -> right);
  return max(lh, rh) + 1;
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
  print(root);
  cout<<endl<<height(root);

  return 0;
}
