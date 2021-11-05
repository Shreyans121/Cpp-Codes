#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key) {
  int beg = 0, end = n-1, mid;
  int ans = -1;

  while(beg <= end) {
    mid = beg + (end - beg)/2;

    if(arr[mid] == key) {
      ans = mid;
      if(arr[mid - 1] == key) {
        end = mid - 1;
      }
      else {
        return ans;
      }
    }
    else if(arr[mid] > key) {
      end = mid - 1;
    }
    else {
      beg = mid + 1;
    }
  }
  return ans;
}

int lastOcc(int arr[], int n, int key) {
  int beg = 0, end = n-1, mid;
  int ans = -1;

  while(beg <= end) {
    mid = beg + (end - beg)/2;

    if(arr[mid] == key) {
      ans = mid;
      if(arr[mid + 1] == key) {
        beg = mid + 1;
      }
      else {
        return ans;
      }
    }
    else if(arr[mid] > key) {
      end = mid - 1;
    }
    else {
      beg = mid + 1;
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  int n;
  int arr[100];
  int key;

  cin>>n;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }
  int t;
  cin>>t;

  while(t--) {
    cin>>key;
    cout<<firstOcc(arr, n, key)<<endl;
    cout<<lastOcc(arr, n, key)<<endl;
  }

  return 0;
}
