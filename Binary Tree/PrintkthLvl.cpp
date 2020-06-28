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

void printkthLvl(node* root, int k) {
  if(root == NULL) {
    return;
  }
  if(k == 1) {
    cout<<root -> data<<" ";
  }
  printkthLvl(root -> left, k-1);
  printkthLvl(root -> right, k-1);
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
  cout<<endl;
  int k;
  cin>>k;
  printkthLvl(root, k);

  return 0;
}
