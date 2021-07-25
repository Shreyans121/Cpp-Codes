#include<iostream>
#include<climits>
using namespace std;

int coinChangeTD(int n, int coins[], int t, int dp[]) {
  if(n == 0) {
    return 0;
  }

  if(dp[n] != 0) {
    return dp[n];
  }

  int ans = INT_MAX;
  for(int i = 0; i<t; i++) {
    if(n - coins[i] >= 0) {
      int subprob = coinChangeTD(n - coins[i], coins, t, dp);
      ans = min(ans, subprob + 1);
    }
  }
  dp[n] = ans;
  return ans;
}

int coinChangeBU(int n, int coins[], int t) {
  int dp[100] = {0};

  for(int i = 1; i<=n; i++) {
    dp[i] = INT_MAX;
    for(int j = 0; j<t; j++) {
      if(i - coins[j] >= 0) {
        dp[i] = min(dp[i], dp[i-coins[j]] + 1);
      }
    }
  }
  for (int k = 0; k <= n; k++) {
    cout<<k<<" "<<dp[k]<<" \n";
  }
  cout<<endl;
  return dp[n];
}

int main() {
  int n;
  cin>>n;
  int dp[100] = {0};
  int coins[] = {1, 7, 10};
  int t = sizeof(coins)/sizeof(int);

  cout<<coinChangeTD(n, coins, t, dp)<<endl;
  cout<<coinChangeBU(n, coins, t)<<endl;
  // cout<<fibSpaceOpt(n)<<endl;
}
