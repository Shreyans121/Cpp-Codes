#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int ans = 0;
  int gap = 2;
  for(int i = 1; i<=n*n; ) {
    int flag = 4;
    while(flag > 0) {
      // cout<<ans<<" ";
      ans += i;
      flag--;
      i += gap;
      if(i>n*n) {
        break;
      }
    }
    gap += 2;
  }

  cout<<ans<<endl;

  return 0;
}
