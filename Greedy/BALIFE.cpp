#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int operations(vector<int> cpu, int n) {
  int sum = 0;
  for(int i = 0; i<n; i++) {
    sum += cpu[i];
  }
  if(sum % n != 0) {
    return -1;
  }
  else {
    sum = sum/n;
  }

  int lsum = cpu[0];
  int diff = (sum-lsum>0)?(sum-lsum):(lsum-sum);
  int count = diff;

  for(int i = 1; i<n-1; i++) {
    lsum += cpu[i];
    int temp = ((i+1)*sum)-lsum;
    diff = (temp>0)?(temp):(-1*temp);
    count = max(count, diff);
  }

  return count;
}

int main() {
  int n;
  vector<int> cpu;
  cin>>n;
  int ip;
  for(int i = 0; i<n; i++) {
    cin>>ip;
    cpu.push_back(ip);
  }

  cout<<operations(cpu, n);
}
