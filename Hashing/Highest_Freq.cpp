#include<iostream>
#include<map>
using namespace std;

int main() {
  int n;
  map<int, int> freq;
  cin>>n;
  for(int i = 0; i<n; i++) {
    int temp;
    cin>>temp;
    freq[temp] += 1;
  }
  int max, max_freq = 1;
  auto max_itr = freq.begin();
  max = max_itr -> first;
  for(auto itr = max_itr; itr != freq.end(); itr++) {
    if(max_freq < itr -> second) {
      max_freq = itr -> second;
      max = itr -> first;
    }
  }
  cout<<max;
}
