#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;

  int num = 1;

  while(t--) {
    int x, y;
    cin>>x>>y;

    string cj;
    cin>>cj;

    int ans = 0;
    int n = cj.length();

    int prev = 'I';

    for(int i = 0; i<n; i++) {
      if(cj[i] == 'C') {
        if(prev == 'J') {
          ans += y;
        }
        prev = 'C';
      }
      else if(cj[i] == 'J') {
        if(prev == 'C') {
          ans += x;
        }
        prev = 'J';
      }
      // cout<<i<<" "<<cj[i]<<" "<<ans<<" "<<prev<<endl;
    }

    cout<<"Case #"<<num<<": "<<ans<<endl;
    num++;
  }
  return 0;
}
