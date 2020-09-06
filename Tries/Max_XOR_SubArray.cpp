#include<iostream>
using namespace std;

class node {
public:
  node* left;
  node* right;
};

class trie {
  node* root;
public:
  trie() {
    root = new node();
  }
  void insert(int n) {
    node* temp = root;
    for(int i = 31; i>=0; i--) {
      int bit = (n>>i)&1;
      if(bit) {
        if(temp -> right == NULL) {
          temp -> right = new node();
        }
        temp = temp -> right;
      }
      else {
        if(temp -> left == NULL) {
          temp -> left = new node();
        }
        temp = temp -> left;
      }
    }
  }
  int max_xor_helper(int val) {
    int current_ans = 0;
    node* temp = root;

    for(int j = 31; j>=0; j--) {
      int bit = (val>>j)&1;
      if(bit) {
        if(temp -> left != NULL) {
          temp = temp -> left;
          current_ans += 1<<j;
        }
        else {
          temp = temp -> right;
        }
      }
      else {
        if(temp -> right != NULL) {
          temp = temp -> right;
          current_ans += 1<<j;
        }
        else {
          temp = temp -> left;
        }
      }
    }
    return current_ans;
  }
  int max_xor(int *input, int n) {
    int max_xor = 0;

    for(int i = 0; i<n; i++) {
      insert(input[i]);
      int current_xor = max_xor_helper(input[i]);
      cout<<current_xor<<" ";
      max_xor = max(current_xor, max_xor);
    }
    cout<<endl;
    return max_xor;
  }
};

int main() {
  int input[1000], n, xored[1000];
  cin>>n;
  for(int i = 0; i<n; i++) {
    cin>>input[i];
  }
  xored[0] = 0;
  for(int i = 1; i<n; i++) {
    xored[i] = input[i] ^ xored[i-1];
    // cout<<"";
  }
  // cout<<endl;
  trie t;
  if(n == 1) {
	  cout<<input[0];
  }
  else{
    // cout<<endl;
  	cout<<t.max_xor(xored, n);
  }

  return 0;
}
