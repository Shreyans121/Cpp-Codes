#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n;
  cin>>n;
  stack <int> s, sp;
  for(int i = 0; i<n; i++) {
    s.push(i);
  }
  while(!s.empty()) {
    sp.push(s.top());
    s.pop();
  }

  while (!sp.empty()) {
    cout<<sp.top()<<" ";
    sp.pop();
  }
}
