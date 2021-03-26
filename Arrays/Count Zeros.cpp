#include<iostream>
using namespace std;

int countZeroes(int arr[], int n) {
    int beg = 0;
    int end = n;

    while(beg<=end) {
        int mid = beg + (end-beg)/2;

        if(arr[mid] == 1) {
            beg = mid+1;
        }
        else if(arr[mid] == 0) {
            while(arr[mid] == 0) {
                mid--;
            }
            return n - mid - 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
  int arr[100], n;
  cin>>n;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  cout<<endl<<countZeroes(arr, n);

  return 0;
}
