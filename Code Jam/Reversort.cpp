#include <bits/stdc++.h>
using namespace std;

int reversort(int arr[100], int n) {
  int cost = 0;

  for(int i = 1; i<n; i++) {
    int j = int(min_element(arr + i - 1, arr + n) - arr) + 1;
    reverse(arr + i - 1, arr + j);
    cost += (j - i + 1);
  }
  return cost;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;

  int num = 1;

  while(t--) {
    int n, arr[100];
    cin>>n;

    for(int i = 0; i<n; i++) {
      cin>>arr[i];
    }

    cout<<"Case #"<<num<<": "<<reversort(arr, n)<<endl;
    num++;
  }

  return 0;
}
