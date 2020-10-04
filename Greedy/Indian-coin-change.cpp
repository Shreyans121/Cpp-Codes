#include<iostream>
#include<algorithm>
using namespace std;

int change(int coins[], int n, int amt) {
  int count = 0;
  while(amt > 0) {
    int idx = upper_bound(coins, coins + n, amt) - 1 - coins;
    amt = amt - coins[idx];
    count++;
  }
  return count;
}

int main() {
  int amt;
  cin>>amt;

  int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
  int n = 10;
  cout<<change(coins, n, amt);

  return 0;
}
