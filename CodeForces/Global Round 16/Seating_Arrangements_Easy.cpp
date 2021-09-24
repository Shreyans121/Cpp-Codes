#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--) {
    int n, m;
    cin>>n>>m;

    vector<int> vec(m, 0);
    vector<int> pos(m+1, 0);
    unordered_map<int, bool> seated;
    unordered_map<int, int> count;

    for(int i = 0; i<m; i++) {
      int temp;
      cin>>temp;
      vec[i] = temp;
      count[vec[i]]++;

      int shift = count[vec[i]];

      while(shift>1) {
        pos[temp] += 1;
        temp++;
        shift--;
      }

      seated[vec[i]] = true;
      pos[temp] = vec[i];
    }

    int ans = 0;

    for(int i = 1; i<=m; i++) {
      int cost = 0;
      for(int j = 0; j<vec[i]; j++) {
        if(seated[j]) {
          cost++;
        }
      }

      ans += cost;
    }
    for(int i = 0; i<n; i++) {

    }
    cout<<ans<<endl;
  }
  return 0;
}
