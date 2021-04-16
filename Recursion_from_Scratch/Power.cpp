#include<iostream>
using namespace std;

double power(double a, double n) {
  if(n == 0) {
    return 1;
  }
  return a * power(a, n-1);
}

int main(int argc, char const *argv[]) {
  double a, n;
  cin>>a>>n;

  double ans = (n>=0)?(power(a, n)):(1/power(a, -1*n));
  cout<<ans;
  return 0;
}
