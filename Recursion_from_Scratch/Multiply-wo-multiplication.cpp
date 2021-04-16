#include<iostream>
using namespace std;

int mul = 0;

int mulint(int x, int y) {
  if(x == 0)
    return mul;

  mul += y;

  return mulint(x-1, y);
}

int main(int argc, char const *argv[]) {
  int x, y;
  cin>>x>>y;

  cout<<mulint(x, y);
  return 0;
}
