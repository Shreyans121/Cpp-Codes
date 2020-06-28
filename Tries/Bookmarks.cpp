#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
  char data;
  unordered_map <char, node*> children;
  bool end;

  node(char d) {
    data = d;
    end = false;
  }
};

class trie {
  node* root;
  int count;
public:
  trie() {
    root = new node('\0');
    count = 0;
  }

  void addURL(char* w) {
    node* temp = root;
    for(int i = 0; w[i] != '\0'; i++) {
      char ch = w[i];
      if(temp -> children.count(ch)) {
        temp = temp -> children[ch];
      }
      else {
        node* n = new node(ch);
        temp -> children[ch] = n;
        temp = n;
      }
    }
    temp -> end = true;
  }

  bool getURL(char* w) {
    node* temp = root;
    for(int i = 0; w[i] != '\0'; i++) {
      char ch = w[i];
      if(temp -> children.count(ch)) {
        temp = temp -> children[ch];
      }
      else {
        return false;
      }
    }
    return temp -> end;
  }
};

int main() {
  int n;
  cin>>n;
  trie t;
  char links[1000][10];
  for(int i = 0; i<n; i++) {
    cin>>links[i];
    t.addURL(links[i]);
  }
  char check[1000][1];
  cin>>check[0];
  cout<<t.getURL(check[0]);
}
