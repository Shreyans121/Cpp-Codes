#include<iostream>
using namespace std;

bool sort(int arr[100], int n) {
  if(n == 0 or n == 1) {
    return true;
  }

  if(arr[0] <= arr[1] and sort(arr+1, n-1)) {
    return true;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int n, arr[100];
  cin>>n;
  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  cout<<sort(arr, n);
  return 0;
}
