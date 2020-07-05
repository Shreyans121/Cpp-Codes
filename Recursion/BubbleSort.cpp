#include <iostream>
using namespace std;

void bubbleSort(int arr[], int i, int n){
  if(n == 1){
    return;
  }
  if(i == n -1 ) {
    return bubbleSort(arr, 0, n-1);
  }
  if(arr[i] > arr[i+1]) {
    swap(arr[i], arr[i+1]);
  }
  bubbleSort(arr, i+1, n);
  return;

}

void bubbleSort(int *arr, int n) {
  if(n == 1) {
    return;
  }
  for(int j = 0; j<n-1; j++) {
    if(arr[j]>arr[j+1]) {
      swap(arr[j], arr[j+1]);
    }
  }
  bubbleSort(arr, n-1);
}

int main() {
  int n, arr[10];
  cin>>n;

  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  bubbleSort(arr, 0, n);
  for(int i = 0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
}
