#include<iostream>
#include<map>
#include<list>
using namespace std;

int main() {
  int n;
  map<int, int> exist;
  list<int> l;
  cin>>n;
  for(int i = 0; i<n; i++) {
    int temp;
    cin>>temp;
    exist[temp] += 1;
  }
  for(int i = 0; i<n; i++) {
    int temp;
    cin>>temp;
    auto itr = exist.find(temp);
    if(itr != exist.end() && itr -> second) {
      l.push_back(itr->first);
      itr->second -= 1;
    }
  }
  l.sort();
  cout<<"[";
  // for(auto itr = l.begin(); itr!=l.end(); itr++) {
  //   cout<<*itr;
  //   l.pop_front();
  //   string str = ((itr) != (l.rbegin()) ? ", " : "]");
  //   cout<<str;
  // }
  while(!l.empty()) {
    cout<<l.front();
    l.pop_front();
    string str = ((!l.empty()) ? ", " : "]");
    cout<<str;
  }
}
