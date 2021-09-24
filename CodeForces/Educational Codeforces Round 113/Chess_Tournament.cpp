#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(int argc, char const *argv[]) {
  int t; cin>>t;

  while(t--) {
    int n; cin>>n;
    string str; cin>>str;
    unordered_set<int> st;

    vector<vector<char>> vec(n+1, vector<char>(n+1));
    for(int i = 1; i<=n; i++) {
      vec[i][i] = 'X';
    }

    for(int i = 1; i<=n; i++) {
      if(str[i-1] == '1') {
        for(int j = 1; j<=n; j++) {
          if(i != j) {
            vec[i][j] = '=';
            vec[j][i] = '=';
          }
        }
      }
      else {
        st.insert(i);
      }
    }

    for(int i = 1; i<=n; i++) {
      for(int j = i+1; j<=n; j++) {
        if(vec[i][j] != '=') {
          if(st.find(i) != st.end()) {
            vec[i][j] = '+';
            vec[j][i] = '-';
            st.erase(i);
          }
          else {
            vec[i][j] = '-';
            vec[j][i] = '+';
            st.erase(j);
          }
        }
      }
    }
    if(st.size() == 0) {
      cout<<"YES"<<endl;
      for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
          if(vec[i][j] == ' ') {
            vec[i][j] = '=';
            vec[j][i] = '=';
          }
          cout<<vec[i][j];
        }
        cout<<endl;
      }
    }
    else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
