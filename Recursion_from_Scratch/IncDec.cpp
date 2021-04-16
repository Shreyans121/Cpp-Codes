#include<iostream>
using namespace std;

void inc(int n, int i = 1) {
  if(n+1 == i) {
    return;
  }
  inc(n, i + 1);
  cout<<i<<" ";
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;

  inc(n);
  cout<<endl;
  // dec(n);
  return 0;
}
