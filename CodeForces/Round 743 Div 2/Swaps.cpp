#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;

    vector<int> arr(n);
    vector<int> brr(n);

    for(int i = 0; i<n; i++) {
      cin>>arr[i];
    }

    for(int i = 0; i<n; i++) {
      cin>>brr[i];
    }

    int itr;

    for(itr = 0; itr<n; itr++) {
      if(arr[itr] < brr[0]) {
        break;
      }
    }

    cout<<itr<<endl;
  }
  return 0;
}
