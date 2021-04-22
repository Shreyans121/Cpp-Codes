#include<iostream>
using namespace std;
int binStrings(int n) {
  if(n <= 1) {
    return 2;
  }

  return binStrings(n-1) + binStrings(n-2);
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;

  cout<<binStrings(n);

  return 0;
}
