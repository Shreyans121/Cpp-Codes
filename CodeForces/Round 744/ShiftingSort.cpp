#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;
    vector<int> vec(n+1);

    for(int i = 1; i<n; i++) {
      cin>>vec[i];
    }
    int i = 2;
    int cnt = 1;

    vector<vector<int>> ans;
    while(i < n and cnt <= n) {
      if(vec[i-1] > vec[i]) {
        int j = i-1;
        i++;
        while(vec[j] > vec[i] and i < n) {
          i++;
        }

        if(i == n and vec[j] < vec[i]) {
            i = n-1;
        }

        vector<int> ok(3);
        ok[0] = j;
        ok[1] = i;
        ok[2] = 1;

        ans.push_back(ok);

        int temp = vec[j];
        for(int k = j; k<i; k++) {
          vec[k] = vec[k+1];
        }
        vec[i] = temp;
      }
      else {
        i++;
      }

      if(i == n-1) {
        cnt++;
        i = 2;
      }
    }

    cout<<ans.size()<<endl;
    for(auto itr: ans) {
      cout<<itr[0]<<" "<<itr[1]<<" "<<itr[2]<<endl;
    }

  }
  return 0;
}
