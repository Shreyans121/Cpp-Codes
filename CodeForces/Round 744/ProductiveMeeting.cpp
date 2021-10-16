#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool helper(const vector<int>& v1, const vector<int>& v2) {
 return v1[1] < v2[1];
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;

    vector<vector<int>> arr(n+1, vector<int>(2));
    int ip;
    for(int i = 1; i<n+1; i++) {
      cin>>ip;
      arr[i][0] = i;
      arr[i][1] = ip;
    }

    sort(arr.begin(), arr.end(), helper);
    vector<pair<int, int>> ans;

    int ptr1 = 1;
    int ptr2 = n;

    while(n--) {
      while(arr[ptr1][1] == 0) {
        ptr1++;
      }
      while(arr[ptr2][1] == 0) {
        ptr2--;
      }

      if(ptr1 >= ptr2) {
          break;
      }

      ans.push_back({arr[ptr1][0], arr[ptr2][0]});
    //   cout<<arr[ptr1][0]<<" "<<arr[ptr2][0]<<endl;
    //   cout<<arr[ptr1][1]<<" "<<arr[ptr2][1]<<endl<<endl;
      arr[ptr1][1]--;
      arr[ptr2][1]--;
    }
    // cout<<endl;
    int ans_size = ans.size();
    cout<<ans_size<<endl;
    for(int itr = 0; itr<ans_size; itr++) {
      cout<<ans[itr].first<<" "<<ans[itr].second<<endl;
    }
  }

  return 0;
}
