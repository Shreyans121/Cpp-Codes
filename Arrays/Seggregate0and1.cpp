#include<iostream>
using namespace std;

void segregate0and1(int arr[], int n) {
        int ptr0, ptr1;
        ptr0 = 0;

        while(arr[ptr0] == 0 && ptr0 < n) {
            ptr0++;
        }

        for(int ptr1 = ptr0; ptr1<n; ptr1++) {
            if(arr[ptr1] == 0) {
                swap(arr[ptr0], arr[ptr1]);
                ptr0++;
            }
        }
    }

int main(int argc, char const *argv[]) {
  int arr[100], n;
  cin>>n;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  segregate0and1(arr, n);

  for(int i = 0; i<n; i++) {
    cout<<arr[i]<<" ";
  }

  return 0;
}
