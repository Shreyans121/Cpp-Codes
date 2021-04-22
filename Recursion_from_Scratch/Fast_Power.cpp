#include<iostream>
#include<cmath>
using namespace std;

int fastPower(int a, int p) {
  if(p == 0) {
    return 1;
  }

  if(p%2 != 0) {
    return a * pow(fastPower(a, p/2), 2);
  }

  return pow(fastPower(a, p/2), 2);
}

int main(int argc, char const *argv[]) {
  int a;
  int p;

  cin>>a>>p;

  cout<<fastPower(a, p);
  return 0;
}
