#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, target;
  cin>>n;

  int arr[1000];
  unordered_map<int, bool> mp;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
    mp[arr[i]] = "true";
  }

  cin>>target;

  for(int i = 0; i<n; i++) {
    cout<<i<<" "<<mp[arr[i]]<<endl;
    if(mp[target - arr[i]] && mp[arr[i]]) {
      cout<<min(arr[i], target - arr[i])
          <<" and "
          <<max(arr[i], target - arr[i])
          <<endl;

      auto itr = mp.at(arr[i]);
      itr->second = "false";
      cout<<i<<" "<<mp[arr[i]]<<endl;
    }
  }

  return 0;
}
