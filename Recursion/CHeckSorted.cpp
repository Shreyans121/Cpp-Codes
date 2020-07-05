#include <iostream>
using namespace std;

bool isSorted(int arr[100], int n) {
  if(n == 0 || n == 1) {
    return true;
  }
  if(arr[0] <= arr[1] and isSorted(arr+1, n-1))
    return true;
  else
    return false;
}

int main() {
  int n, arr[100];
  cin>>n;

  for(int i = 0; i<n; i++)
    cin>>arr[i];

  cout<<isSorted(arr, n);
}
