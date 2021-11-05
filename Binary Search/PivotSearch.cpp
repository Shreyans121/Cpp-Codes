#inclyude<iostream>
using namespace std;

int pivotSearch(int arr[], int n, int key) {
  int beg = 0, end = n-1, mid;

  while(beg <= mid) {
    mid = beg + (end - beg)/2;

    if(arr[mid] == key) {
      return mid;
    }
    else if(arr[beg] <= arr[mid]) {
      if(arr)
    }
  }
}

int main(int argc, char const *argv[]) {
  int n, arr[100], key;

  cin>>n;
  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }
  cin>>key;
  return 0;
}
