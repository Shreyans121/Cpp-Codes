#include<bits/stdc++.h>
using namespace std;

int strToInt(string str, int i = 0, int x = 0) {
  if(str[i] == '\0') {
    return x;
  }

  x = x*10 + (str[i] - '0');
  return strToInt(str, i+1, x);
}


int main(int argc, char const *argv[]) {
  string str;
  cin>>str;

  cout<<typeid(strToInt(str)).name();

  return 0;
}
