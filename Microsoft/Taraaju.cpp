#include<bits/stdc++>
using namespace std;

class Node {
  int data;
  Node* left;
  Node* right;

  Node(int d) {
    this -> data = d;
    left = right = nullptr;
  }
};

// node* buildTree() {
//   int n;
//   node* root = new node(n);
//
//   vector<pair<int, int>> vec(n+1);
//   for(int i = 1; i<=n; i++) {
//     int n1, n2;
//     cin>>n1>>n2;
//
//     vec[i] = make_pair(n1, n2);
//   }
//
//   for(int i = 1; i<=n; i++) {
//
//
//     node* lt = new node(vec[i].first);
//     node* rt = new node(vec[i].second);
//     root -> left = lt;
//     root -> right = rt;
//   }
// }
//
// node* preOrder() {
//   int d;
//   cin>>d;
//
//   if(d == -1) {
//     return NULL;
//   }
//
//   node* root = new node(d);
//   root -> left = preOrder();
//   root -> right = preOrder();
//
//   return root;
// }

int Solve(vector<vector<int>> &arr){
    queue<Node*> q;
    Node *root = new Node(0);
    q.push(root);
    int i = 0;
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front->data == 0){
            if(arr[i][0] > 0){
                front->left = new Node(0);
                q.push(front->left);
            }
            if(arr[i][0] <= 0){
                int d = -arr[i][0];
                front->left = new Node(d);
            }
            if(arr[i][1] > 0){
                front->right = new Node(0);
                q.push(front->right);
            }
            if(arr[i][1] <= 0){
                int d = -arr[i][1];
                front->right = new Node(d);
            }
        }
        i++;
    }
    return travel(root);
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vector<pair<int, int>> vec(n);
  for(int i = 0; i<n; i++) {
    int n1, n2;
    cin>>n1>>n2;

    if(n1 > 0) {

    }
  }
  return 0;
}
