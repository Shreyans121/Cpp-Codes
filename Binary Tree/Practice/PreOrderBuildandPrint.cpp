#include<iostream>
using namespace std;

class node {
public:
  int data;
  node* left;
  node* right;

  node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

node* buildTree() {
  int ip;
  cin>>ip;

  if(ip == -1) {
    return NULL;
  }

  node* root = new node(ip);
  root -> left = buildTree();
  root -> right = buildTree();

  return root;
}

void PreOrder(node* root) {
  if(!root) {
    return;
  }

  cout<<root -> data<<" ";
  PreOrder(root -> left);
  PreOrder(root -> right);
}

void InOrder(node* root) {
  if(!root) {
    return;
  }

  InOrder(root -> left);
  cout<<root -> data;
  InOrder(root -> right);
}

void PostOrder(node* root) {
  if(!root) {
    return;
  }
  PostOrder(root -> left);
  PostOrder(root -> right);
  cout<<root -> data;
}

int main(int argc, char const *argv[]) {
  node* root = buildTree();
  PreOrder(root);
  InOrder(root);
  PostOrder(root);
  return 0;
}
