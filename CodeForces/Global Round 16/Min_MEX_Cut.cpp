#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--) {
    string str;
    cin>>str;
    int n = str.size();
    bool flag = false;

    int cnt0 = 0;
    bool occ0 = false;
    bool occ1 = false;
    for(int i = 0; i<n; i++) {
      if(str[i] == '0') {
        if(occ0 == false) {
          cnt0++;
        }
        occ0 = true;
        occ1 = false;
      }
      else {
        occ1 = true;
        occ0 = false;
      }

      if(cnt0 >= 2) {
        cout<<2<<endl;
        flag = true;
        break;
      }
    }
    if(!flag) {
      cout<<cnt0<<endl;
    }
  }
  return 0;
}
