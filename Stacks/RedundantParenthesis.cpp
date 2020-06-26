#include <iostream>
#include <stack>
#include <string>
using namespace std;

void duplicate(string str) {
  // cout<<"In Function"<<endl;
  stack <int> s;
  for(int i = 0; str[i] != '\0'; i++) {

    if(str[i] == '(') {
      // cout<<"Pushed "<<str[i]<<endl;
      s.push(40);
      continue;
    }
    else
    if (str[i] == ')') {
      if(s.top() == 42) {
        // cout<<"Popped "<<s.top()<<endl;
        s.pop();
      }
      else {
        cout<<"Duplicate"<<endl;
        return;
      }

      if(s.top() == 40) {
        // cout<<"Popped "<<s.top()<<endl;
        s.pop();
      }
      else {
        cout<<"Duplicate"<<endl;
        return;
      }
      continue;
    }
    else {
      while (str[i+1] != '(' && str[i+1] != ')') {
        ++i;
      }
      s.push(42);
    }
  }

  if(s.empty()) {
    cout<<"Not Duplicates"<<endl;
    return;
  }
  else {
    cout<<"Duplicate"<<endl;
    return;
  }
}

int main() {
  int t;
  cin>>t;

  while(t>0) {
    string str;
    cin>>str;

    // cout<<"Above Call"<<endl;
    duplicate(str);
    // cout<<"Below Call"<<endl;


    t--;
  }
  return 0;
}
