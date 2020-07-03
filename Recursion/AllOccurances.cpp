#include <iostream>
using namespace std;

int allOccStore(int *arr, int i, int n, int k, int *out, int j) {
  if(i == n) {
    return j;
  }
  if(arr[i] == k) {
    out[j] = i;
    return allOccStore(arr, i+1, n, k, out, j+1);
  }
  return allOccStore(arr, i+1, n, k, out, j);
}

void allOcc(int *arr, int i, int n, int k) {
  if(i == n) {
    return;
  }
  if(arr[i] == k) {
    cout<<i<<" ";
  }
  allOcc(arr, i+1, n, k);
}

int main() {
  int n, arr[100];
  cin>>n;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  int key;
  cin>>key;
  // cout<<"Indexes are: ";
  allOcc(arr, 0, n, key);

  // int out[100];
  // int j = allOccStore(arr, 0, n, key, out, 0);

  // cout<<endl<<"Indexes are: ";
  // for(int i = 0; i<j; i++) {
  //   cout<<out[i]<<" ";
  // }
}
