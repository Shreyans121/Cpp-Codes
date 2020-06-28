#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
  char data;
  unordered_map <char, node*> children;
  bool end;

  node(char d) {
    this -> data = d;
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

  void insert(char *w) {
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

  bool find(char *w) {
    node* temp = root;

    for(int i = 0; w[i] != '\0'; i++) {
      char ch = w[i];
      if(temp -> children.count(ch) == 0) {
        return false;
      }
      else {
        temp = temp -> children[ch];
      }
    }
    return temp -> end;
  }
};

int main() {
  trie t;
  char words[][10] = {"ant", "hello", "not", "news", "apple"};

  for(int i = 0; i<5; i++) {
    t.insert(words[i]);
  }

  if(t.find("app")) {
    cout<<"Present";
  }
  else
    cout<<"Not Present";

  return 0;
}
