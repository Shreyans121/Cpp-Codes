//Two types : set and unordered_set
//Unique and Ordered (SET)
//Uses Red Black tree
// Cannot uptate an element
//Insert, Iterate, Check/Search

#include<iostream>
#include<set>
using namespace std;

int main() {
  int arr[] = {1, 2, 5, 4, 6, 4, 1};
  int n = sizeof(arr)/sizeof(int);

  set<int> s;
  for(int i = 0; i<n; i++) {
    s.insert(arr[i]);
  }

  //Erase
  s.erase(4);
  auto it = s.find(5);
  s.erase(it);
  //print
  for(set<int>::iterator it = s.begin(); it!=s.end(); it++) {
    cout<<*it<<",";
  }
  cout<<endl;

  set <pair<int, int>> sp;

  sp.insert(make_pair(10, 20));
  sp.insert(make_pair(2, 50));
  sp.insert(make_pair(6, 20));
  sp.insert(make_pair(20, 35));
  sp.insert(make_pair(11, 23));
  sp.insert(make_pair(10, 20));
  sp.insert(make_pair(6, 11));
  sp.insert(make_pair(1, 4));

  for(auto p:sp) {
    cout<<p.first<<" -> "<<p.second<<endl;
  }

  auto itr = sp.upper_bound(make_pair(6, 11));
  cout<<itr -> first<<"and"<<itr -> second;

  return 0;







}
