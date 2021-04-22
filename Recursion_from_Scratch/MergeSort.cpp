#include<iostream>
using namespace std;

void mergeSort(int *arr, int n) {
  if(n == 0) {
    return;
  }

  mergeSort(arr, n/2);
  int i = n;
  if(arr[i]> arr[i+1]) {
    swap(arr[i], arr[i+1]);
  }

  return;
}

int main(int argc, char const *argv[]) {
  int n, arr[100];
  cin>>n;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  mergeSort(arr, n);

  for(int i = 0; i<n; i++) {
    cout<<arr[i]<<" ";
  }

  return 0;
}
