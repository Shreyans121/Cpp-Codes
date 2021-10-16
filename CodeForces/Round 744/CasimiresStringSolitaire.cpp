#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;

  while(t--) {
    string str;
    cin>>str;

    int cnt = 0;

    for(int i = 0; str[i] != '\0'; i++) {
      if(str[i] == 'B') {
        cnt--;
      }
      else {
        cnt++;
      }
    }

    if(cnt == 0) {
      cout<<"YES"<<endl;
    }
    else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
