#include<iostream>
using namespace std;
int RecursiveBsearch(int arr[], int start, int end, int element) {
    if(start>end)
      return -1;
    int mid = (start+end)/2;
    if( arr[mid] == element )
      return mid;
    else if( element < arr[mid] )
      RecursiveBsearch(arr, start, mid-1, element);
    else
      RecursiveBsearch(arr, mid+1, end, element);
}
int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  int arr[n];
  cout << "Enter elements:" << endl;
  for(int i = 0; i<n; i++) {
   cin >> arr[i];
  }
  int k;
  cout<<"Enter the elemnet to be searched: ";
  cin>>k;
  int pos = RecursiveBsearch(arr,0,n-1,k);
  if(pos != -1) {
    cout<<k<<" is found at Index "<<pos;
  }
  else {
    cout<<"Element not Found";
  }
  return 0;
}
