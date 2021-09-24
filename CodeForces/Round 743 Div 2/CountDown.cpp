#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;

    string str;
    cin>>str;

    int cnt = 0;

    if(str[n-1] != '0') {
      cnt += (str[n-1] - '0');
    }

    for(int i = n-2; i>=0; i--) {
      if(str[i] != '0') {
        cnt += (str[i] - '0') + 1;
      }
    }

    cout<<cnt<<endl;
  }
  return 0;
}
