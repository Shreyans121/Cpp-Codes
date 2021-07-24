#include<iostream>
#include<list>
#include<unordered_map>
#include<cstring>
using namespace std;

class Graph {
  int v;
  unordered_map<string, list<pair<string, int>>> mp;

public:
  Graph(int v) {
    this -> v = v;
  }

  void addEdge(string x, string y, bool bdir, int wt) {
    mp[x].push_back(make_pair(y, wt));
    if(bdir) {
      mp[y].push_back(make_pair(x, wt));
    }
  }

  void printGraph() {
    for(auto ele: mp) {
      string city = ele.first;
      cout<<city<< " -> ";

      for(auto nbr: ele.second) {
        cout<<"("<<nbr.first<<", "<<nbr.second<<") ";
      }
      cout<<endl;
    }
  }
};

int main(int argc, char const *argv[]) {
  Graph g(4);
  g.addEdge("A", "B", true, 20);
  g.addEdge("B", "D", true, 40);
  g.addEdge("A", "C", true, 10);
  g.addEdge("C", "D", true, 40);
  g.addEdge("A", "D", false, 50);


  g.printGraph();
  return 0;
}
