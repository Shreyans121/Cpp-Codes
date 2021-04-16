#include<iostream>
using namespace std;

int firstOcc(int arr[100], int n, int k) {
  if(n == 0) {
    return -1;
  }

  if(arr[0] == k && firstOcc(arr+1, n-1, k) == -1) {
    return 0;
  }
  else {
    if(firstOcc(arr+1, n-1, k) >= 0) {
      return firstOcc(arr+1, n-1, k) + 1;
    }
    else {
      return -1;
    }
  }
}

int main(int argc, char const *argv[]) {
  int n, k, arr[100];
  cin>>n>>k;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  cout<<firstOcc(arr, nw, k);
  return 0;
}
