#include <iostream>
#include <queue>
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

void bfs(node* root, queue <node*> q) {

  while(!q.empty()) {
    if(q.front() == NULL) {
      q.pop();
      continue;
    }
    cout<<q.front() -> data<<" ";
    q.push(q.front() -> left);
    q.push(q.front() -> right);
    q.pop();
  }

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

  queue <node*> q;
  q.push(root);
  bfs(root, q);



  return 0;
}
