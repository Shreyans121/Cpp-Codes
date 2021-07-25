#include<iostream>
#include<climits>
using namespace std;

int minStepsTD(int n, int dp[]) {
  if(n == 1) {
    return 0;
  }

  if(dp[n] != 0) {
    return dp[n];
  }

  int n1, n2, n3;
  n1 = n2 = n3 = INT_MAX;

  if(n % 3 == 0) {
    n3 = minStepsTD(n/3, dp) + 1;
  }
  if(n % 2 == 0) {
    n2 = minStepsTD(n/2, dp) + 1;
  }
  n1 = minStepsTD(n-1, dp) + 1;

  int ans = min(min(n1, n2), n3);
  return dp[n] = ans;
}

int minStepsBU(int n) {
  if(n == 1) {
    return 0;
  }

  int dp[100] = {0};
  int n1, n2, n3;

  for(int i = 2; i <= n; i++) {
    n1 = n2 = n3 = INT_MAX;
    if(n % 3 == 0) {
      n3 = dp[i/3];
    }
    if(n % 2 == 0) {
      n2 = dp[i/2];
    }
    n1 = dp[i-1];
    dp[i] = min(min(n1, n2), n3) + 1;
  }
  return dp[n];
}

int main() {
  int n;
  cin>>n;
  int dp[100] = {0};

  cout<<minStepsTD(n, dp)<<endl;
  cout<<minStepsBU(n)<<endl;
}
