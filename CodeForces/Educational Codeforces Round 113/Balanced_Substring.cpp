#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int t; cin>>t;

  while(t--) {
    bool flag = false;
    int n; cin>>n;
    string str; cin>>str;

    int cnta = 0, cntb = 0;

    for(int i = 1; i<=n; i++) {
      if(cnta == 0 or cntb == 0) {
        if(str[i-1] == 'a') {
          cnta++;
        }
        else if(str[i-1] == 'b') {
          cntb++;
        }
      }

      if(cnta > 0 and cntb > 0) {
        cout<<i-1<<" "<<i<<endl;
        flag = true;
        break;
      }
    }
    if(!flag) {
      cout<<-1<<" "<<-1<<endl;
    }
  }
  return 0;
}
