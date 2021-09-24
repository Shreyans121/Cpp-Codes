#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t--) {
    int col;
    cin>>col;
    string str1, str2;
    cin>>str1>>str2;

    int sum = 0;
    int n = str1.size();

    for(int i = 0; i<n; i++) {
      if(i < n and str1[i] != str2[i]) {
        sum += 2;
      }
      else if(str1[i] == '0' and str2[i] == '0') {
        if(i < n-1 and str1[i+1] == '1' and str2[i+1] == '1') {
          sum += 2;
          i++;
        }
        else {
          sum += 1;
        }
      }
      else if(str1[i] == '1' and str2[i] == '1') {
        if(i < n-1 and str1[i+1] == '0' and str2[i+1] == '0') {
          sum += 2;
          i++;
        }
      }
    }

    cout<<sum<<endl;

  }
  return 0;
}
