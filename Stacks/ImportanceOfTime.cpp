#include <iostream>
#include <queue>
using namespace std;

int calcTime(queue <int> qc, queue <int> qi, int n) {
  int time = 0;
  while(!qc.empty()) {
    if(qc.front() == qi.front()) {
      qc.pop();
      qi.pop();
      time++;
    }
    else {
      int temp = qc.front();
      qc.pop();
      qc.push(temp);
      time++;
    }
  }
  return time;
}

int main() {
  int n;
  cin>>n;

  queue <int> qc, qi;
  int ip = 0;
  for(int i = 0; i<n; i++) {
    cin>>ip;
    qc.push(ip);
  }
  for(int i = 0; i<n; i++) {
    cin>>ip;
    qi.push(ip);
  }

  cout<<calcTime(qc, qi, n)<<endl;
}
