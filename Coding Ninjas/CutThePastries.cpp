// 4
// 2 7 6 0 0 5
// 7 1 7 10 11 11
// 5 10 2 9 6 8
// 1 9 10 10 4 1
// 4
// y = 6
// x = 2
// x = 4
// x = 9

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m, arr[100000][10];
  cin>>n;

  for(int i = 0; i<n; i++) {
    for(int j = 0; j<6; j++) {
      cin>>arr[i][j];
    }
  }

  for(int i = 0; i<n; i++) {
    arr[i][7] = max(arr[i][0], max(arr[i][2], arr[i][4]));  // x max
    arr[i][8] = min(arr[i][0], min(arr[i][2], arr[i][4]));  // x min
    arr[i][9] = max(arr[i][1], max(arr[i][3], arr[i][5]));  // y max
    arr[i][10] = min(arr[i][1], min(arr[i][3], arr[i][5])); // y min
  }

  cin>>m;

  while(m--) {
    string line;
    cin>>line;

    int cnt = 0;

    if(line[0] == 'x') {
      int x = line[4] - '0';

      for(int i = 0; i<n; i++) {
        if(x > arr[i][8] and x < arr[i][7]) {
          cnt++;
        }
      }
    }
    else if(line[0] == 'y') {
      int y = line[4] - '0';

      for(int i = 0; i<n; i++) {
        if(y > arr[i][10] and y < arr[i][9]) {
          cnt++;
        }
      }
    }

    cout<<cnt<<endl;
  }
  return 0;
}
