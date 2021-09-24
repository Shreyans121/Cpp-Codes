#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--) {
    int n, s;
    cin>>n>>s;

    if(n == 1) {
      cout<<s<<endl;
    }
    else {
      if(n%2 == 0) {
        n = n - (n/2) + 1;
      }
      else {
        n = n - (n/2);
      }

      cout<<s/n<<endl;
    }
  }
  return 0;
}
