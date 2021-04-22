#include<iostream>
using namespace std;

int count = 0;

void ladder(int n, int sum = 0) {
  if(sum == n) {
    count++;
    return;
  }

  if(sum > n) {
    return;
  }
  ladder(n, sum+1);
  ladder(n, sum+2);
  ladder(n, sum+3);

  return;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;

  ladder(n);
  cout<<count;
  return 0;
}
