#include<iostream>
using namespace std;

int addint(int x, int y) {
  if(x == 0)
    return y;

  y += 1;

  return addint(x-1, y);
}

int main(int argc, char const *argv[]) {
  int x, y;
  cin>>x>>y;

  cout<<addint(x, y);
  return 0;
}
