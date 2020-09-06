#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubArray(int n) {
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

    if(sum == 0) {
      curr_length = i + 1;
      max_length = max(max_length, curr_length);
    }
    else
    if(map.find(sum) != map.end()) {
      curr_length = i - (map.find(sum) -> second);
      max_length = max(max_length, curr_length);
    }
  }
  return max_length;
}

int main() {
  int n;
  cin>>n;

  cout<<longestSubArray(n);
  return 0;
}
