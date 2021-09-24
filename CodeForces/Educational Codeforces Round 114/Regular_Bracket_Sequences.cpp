#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<string> generateParenthesis(int n) {
  unordered_set<string> s;
      s.insert("()");
      for(int i=2; i<=n; i++){
          unordered_set<string> new_st;
          for (auto elem: s) {
              for(int j=0; j<elem.size(); j++){
                  string new_s = elem.substr(0,j)+"()"+elem.substr(j,elem.size());
                  new_st.insert(new_s);
              }
          }
          s = new_st;
      }
      vector<string> v(s.begin(), s.end());
      return v;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;

    vector<string> vec;

    vec = generateParenthesis(n);

    for(int i = 0; i<n; i++) {
      cout<<vec[i]<<endl;
    }
  }
  return 0;
}
