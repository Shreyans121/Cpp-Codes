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

node* inOrder() {
  int d;
  cin>>d;

  //Base Case
  if(d == -1) {
    return NULL;
  }

  //Recursive Call
  node* root = new node(d);
  root -> left = inOrder();
  root -> right = inOrder();

  return root;
}

void printIn(node* root) {
  if(root == NULL) {
    return;
  }
  printIn(root -> left);
  cout<<root -> data<<" ";
  printIn(root -> right);
}

void printPost(node* root){
  if(root == NULL) {
    return;
  }
  printPost(root -> left);
  printPost(root -> right);
  cout<<root -> data<<" ";
}

int main() {
  node* root = inOrder();
  printIn(root);
  cout<<endl;
  printPost(root);

  return 0;
}
