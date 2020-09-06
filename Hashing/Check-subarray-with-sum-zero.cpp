#include<iostream>
#include<unordered_set>
using namespace std;

bool checkSum(int a[], int n) {
  unordered_set<int> s;
  int sum = 0;
  for(int i = 0; i<n; i++) {
    sum += a[i];
    if(sum == 0 or s.find(sum) != s.end()) {
      return true;
    }

    s.insert(sum);
  }
  return false;
}

int main() {
  int arr[100], n;

  cin>>n;
  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  if(checkSum(arr, n)) {
    cout<<"Yes";
  }
  else {
    cout<<"No";
  }

  return 0;
}
