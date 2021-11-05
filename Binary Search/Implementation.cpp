#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
  int beg = 0;
  int end = n-1;

  int mid;

  while(beg<=end) {
    mid = beg + (end - beg)/2;

    if(arr[mid] == key) {
      return mid;
    }
    else if(arr[mid] > key) {
      end = mid - 1;
    }
    else {
      beg = mid + 1;
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  int n;
  int arr[100];
  int key;

  cin>>n;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  cin>>key;

  cout<<binarySearch(arr, n, key)<<endl;
  return 0;
}
