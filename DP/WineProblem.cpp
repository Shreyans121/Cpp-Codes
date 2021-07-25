#include<iostream>
#include<climits>
using namespace std;

int wineTD(int wines[], int y, int i, int j, int dp[][100]) {
  if(i > j) {
    return 0;
  }
  // LookUp
  if(dp[i][j] != 0) {
    return dp[i][j];
  }
  int ans;
  ans = max((wines[i] * y + wineTD(wines, y + 1, i + 1, j, dp)),
             wines[j] * y + wineTD(wines, y + 1, i, j - 1, dp));

  return dp[i][j] = ans;
}

// int wineBU(int wines[], int y, int i, int j) {
//   int dp[100][100] = {0};
//   int n = sizeof(wines)/sizeof(int);
//   for(int k = 0; k<n; k++) {
//     for(int idx = 0; idx<n; idx++) {
//       dp[k][k + idx] = (n-1) * wines[k];
//     }
//   }
// }

int main() {
  int wines[] = {2, 3, 5, 1, 4};

  int dp[100][100] = {0};

  cout<<wineTD(wines, 1, 0, (sizeof(wines)/sizeof(int)) - 1, dp)<<endl;
  // cout<<minStepsBU(n)<<endl;
}
