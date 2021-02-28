#include<iostream>
#include<string>
using namespace std;

int substr(string s1, string s2, int i, int j) {
  if(i == s1.length() || j == s2.length())
    return 0;

  if(s1[i] == s2[j]) {
    return 1 + substr(s1, s2, i+1, j+1);
  }
  else {
    return max(substr(s1, s2, i+1, j), substr(s1, s2, i, j+1));
  }
}

int main() {
  string s1, s2;
  cin>>s1>>s2;

  cout<<substr(s1, s2, 0, 0);
}
