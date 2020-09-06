#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubArray(int n, int k) {
  int csum[100];
  unordered_map<int, int> map;
  int sum = 0;

  int max_length = 0;
  int curr_length = 0;

  for(int i = 0; i<n; i++) {
    int temp;
    cin>>temp;
    sum += temp;
    csum[i] = sum;

    if(map.find(sum) == map.end()) {
      map[sum] = i;
    }

    if(sum == k) {
      curr_length = i + 1;
      max_length = max(max_length, curr_length);
    }
    else
    if(map.find(sum - k) != map.end()) {
      curr_length = i - (map.find(sum - k) -> second);
      max_length = max(max_length, curr_length);
    }
  }
  return max_length;
}

int main() {
  int n, k;
  cin>>n>>k;

  cout<<longestSubArray(n, k);
  return 0;
}
