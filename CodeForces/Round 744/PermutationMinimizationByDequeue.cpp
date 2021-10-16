#include<iostream>
#include<vector>
#include<deque>
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

    vector<int> vec(n);

    for(int i = 0; i<n; i++) {
      cin>>vec[i];
    }

    deque<int> dq;

    dq.push_back(vec[0]);

    for(int i = 1; i<n; i++) {
      if(dq.front() > vec[i]) {
        dq.push_front(vec[i]);
      }
      else {
        dq.push_back(vec[i]);
      }
    }
    for(auto itr: dq) {
      cout<<itr<<" ";
    }
    cout<<endl;
  }

  return 0;
}
