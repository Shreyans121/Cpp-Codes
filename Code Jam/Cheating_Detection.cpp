#include <bits/stdc++.h>
using namespace std;

int cheating(string resp[100], int p) {
  
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, p;
  cin>>t>>p;

  int num = 1;

  while(t--) {
    string resp[100];

    for(int i = 0; i<100; i++) {
      cin>>resp[i];
    }

    cout<<"Case #"<<num<<": "<<cheating(resp, p)<<endl;
    num++;
  }

  return 0;
}
