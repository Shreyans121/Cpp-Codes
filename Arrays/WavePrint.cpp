// Input
// 4 4
// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44
//
// Output
// 11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14, END

#include<iostream>
using namespace std;

void wavePrint(int arr[10][10], int m, int n) {
  for(int j = 0; j<n; j++) {
    int limit = m;
    while(limit>0) {
      if(j%2 == 0) {
        cout<<arr[m - limit][j]<<", ";
      }
      else {
        cout<<arr[limit - 1][j]<<", ";
      }
      limit--;
    }
  }
  cout<<"END";
}

int main(int argc, char const *argv[]) {
  int m, n;
  cin>>m>>n;

  int arr[10][10];
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
      cin>>arr[i][j];
    }
  }

  wavePrint(arr, m, n);
  return 0;
}
