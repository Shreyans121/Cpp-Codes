#include<iostream>
using namespace std;

int tilingPattern(int n) {
  if(n < 4) {
    return 1;
  }

  return tilingPattern(n-1) + tilingPattern(n-4);
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;

  cout<<tilingPattern(n);

  return 0;
}
