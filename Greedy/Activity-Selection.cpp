#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sortBySec(const pair<int, int> p1, const pair<int, int> p2) {
  // if(p1.second == p2.second)  {
  //   return (p1.first > p2.first);
  // }
  // else
    return (p1.second < p2.second);
}

int selector(vector<pair<int, int>> p, int n) {
  sort(p.begin(), p.end(), sortBySec);
  int count = 1;

  // for(int i = 0; i<n; i++) {
  //   cout<<p[i].first<<" "<<p[i].second<<endl;
  // }
  int j = 0;
  for(int i = 1; i<n; i++) {
    if(p[i].first>=p[j].second) {
      count++;
      j = i;
    }
  }
  return count;
}

int main() {
  int t;
  cin>>t;

  while (t>0) {
    int n;
    cin>>n;

    vector<pair<int, int>> p;
    for(int i = 0; i<n; i++) {
      int s, e;
      cin>>s>>e;
      p.push_back(make_pair(s, e));
    }

    cout<<selector(p, n)<<endl;
    t--;
  }
  return 0;
}
