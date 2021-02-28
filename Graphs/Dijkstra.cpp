#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
using namespace std;

template <typename T>
class graph {
  unordered_map <T, list<pair<T, int>>> mp;

public:
  void addEdge(T x, T y, int dist, bool bdir=true) {
    mp[x].push_back(make_pair(y, dist));
    if(bdir) {
      mp[y].push_back(make_pair(x, dist));
    }
  }
  void printAdjList() {
    for(auto j: mp) {
      cout<<j.first<<" -> ";

      for(auto l: j.second) {
        cout<<"("<<l.first<<", "<<l.second<<")";
      }
      cout<<endl;
    }
  }
  void dijkstraSSSP(T src) {
    unordered_map<T, int> dist;

    for(auto j: m) {
      dist[j.first] = INT_MAX;
    }

    set<int, T> s;
    dist[src] = 0;
    s.insert(make_pair(0, src));

    while(!s.empty()) {
        auto p = *(s.begin());
        T node = p.second;

        int nodeDist = p.first;
        p.erase(s.begin());

        for(auto nbr: mp[node]) {
          if(nodeDist + nbr.second < dist[nbr.first]) {
            T dest 
          }
        }
    }
  }
};

int main() {
  graph<int> g;

  g.addEdge(1, 2, 1);
  g.addEdge(1, 3, 4);
  g.addEdge(2, 3, 1);
  g.addEdge(3, 4, 2);
  g.addEdge(1, 4, 7);
  g.printAdjList();

  g.dijkstraSSSP(1);
}
