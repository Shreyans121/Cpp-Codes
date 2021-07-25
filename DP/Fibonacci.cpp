#include<iostream>
using namespace std;

int fibTD(int n, int dp[]) {
  if(n == 0 or n == 1) {
    return n;
  }

  if(dp[n] != 0) {
    return dp[n];
  }

  int ans;
  ans = fibTD(n-1, dp) + fibTD(n-2, dp);
  return dp[n] = ans;
}

int fibBU(int n) {
  int dp[100] = {0};
  dp[1] = 1;

  for(int i = 2; i<=n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}

int fibSpaceOpt(int n) {
  if(n == 0 or n == 1) {
    return n;
  }
  int a = 0, b = 1;
  int c;

  for(int i = 2; i<=n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main() {
  int n;
  cin>>n;
  int dp[100] = {0};

  cout<<fibTD(n, dp)<<endl;
  cout<<fibBU(n)<<endl;
  cout<<fibSpaceOpt(n)<<endl;
}
