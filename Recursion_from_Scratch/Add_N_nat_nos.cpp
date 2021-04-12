#include<iostream>
using namespace std;

// int addint(int x, int sum = 0) {
//   if(x == 1)
//     return sum+1;
//
//   sum += x;
//
//   return addint(x-1, sum);
// }

int sum = 0;

void addvoid(int x) {
  if(x == 0) {
    return;
  }

  sum += x;
  addvoid(x-1);
}

int main() {
  int x;
  cin>>x;

  // cout<<addint(x)<<endl;
  addvoid(x);
  cout<<sum;
}
