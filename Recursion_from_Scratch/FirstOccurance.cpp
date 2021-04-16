#include<iostream>
using namespace std;

int firstOcc(int arr[100], int n, int k, int i = 0) {
  if(i == n) {
    return -1;
  }

  if(arr[i] == k) {
    return i;
  }
  return firstOcc(arr, n, k, i + 1);
}

int main(int argc, char const *argv[]) {
  int n, k, arr[100];
  cin>>n>>k;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  cout<<firstOcc(arr, n, k);
  return 0;
}
