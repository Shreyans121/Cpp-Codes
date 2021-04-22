#include<iostream>
using namespace std;

void bubbleSortwLoop(int *arr, int n) {
  if(n == 1) {
    return;
  }
  for(int i = 1; i<n; i++) {
    if(arr[i] < arr[i-1]) {
      swap(arr[i], arr[i-1]);
    }
  }
  bubbleSortwLoop(arr, n-1);
}

void bubbleSort(int *arr, int n, int i = 0) {
  if(n == 1) {
    return;
  }

  if(i == n-1) {
    return bubbleSort(arr, n-1, 0);
  }

  if(arr[i] > arr[i+1]) {
    swap(arr[i], arr[i+1]);
  }

  bubbleSort(arr, n, i+1);
  return;
}

int main(int argc, char const *argv[]) {
  int n, arr[100];
  cin>>n;
  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  bubbleSort(arr, n);

  for(int i = 0; i<n; i++) {
    cout<<arr[i]<<" ";
  }

  return 0;
}
