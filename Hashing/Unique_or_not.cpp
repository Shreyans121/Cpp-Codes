#include<iostream>
#include<map>
using namespace std;

int main() {
  int t;
  cin>>t;

  while(t>0) {
    int l, q;
    map <int, bool> val;
    cin>>l;
    for(int i = 0; i<l; i++) {
      int temp;
      cin>>temp;
      val[temp] = true;
    }

    cin>>q;

    while(q>0) {
      int x;
      cin>>x;
      auto itr = val.find(x);
      if(itr!=val.end()) {
        cout<<"Yes"<<endl;
      }
      else {
        cout<<"No"<<endl;
      }

      q--;
    }

    t--;
  }

	return 0;
}
