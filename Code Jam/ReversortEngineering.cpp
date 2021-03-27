#include<iostream>
using namespace std;

vector<int> buildL(int n) {
  vector<int> l;

  for(int i = 1; i<n+1; i++) {
    l.push_back(i);
  }

  return l;
}

vector<int> operL(int n, int p) {
  vector<int> l;
  if(p<n-1) {
    return l;
  }
  int t = 0;
  int c = 1;

  for(int i = n-1; i>0; i--) {
    c++;

    if(t + c + i - 1 >= p) {
      r = p - t - i + 1;
      l.push_back(r);

      for(int k = 0; k<i-1; k++) {
        l.push_back(1);
      }
      t = p;
      break;
    }
    t += c;
    l.push_back(c);
  }
  if(t<p) {
    return vector<int>();
  }
  return l;
}

vector<int> operate(vector<int> l, ) {
  len = opeL.length();
  for(int i = 0; i<len; i++) {
    int t = l.size() - (i+2);
    sp = t+opel[i];
    l =
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;

  int num = 1;

  while(t--) {

    cout<<"Case #"<<num<<": "<<ans<<endl;
    num++;
  }
  return 0;
}
