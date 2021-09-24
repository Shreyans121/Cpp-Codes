#include<iostream>
#include<list>
#include<queue>
using namespace std;

class graph {
  int v;
  list<int> *l;

public:
  graph(int v) {
    (*this).v = v;
    l = new list<int> [v];
  }

  void addEdge(int x, int y) {
    l[x].push_back(y);
    // l[y].push_back(x);
  }

  bool helper(int node, bool visited[], bool lookup[]) {
    visited[node] = true;
    lookup[node] = true;

    for(auto nbr: l[node]) {
      if(visited[nbr] == true and lookup[nbr] == true) {
        return true;
      }
      else if(!visited[nbr]) {
        bool cycle_mila = helper(nbr, visited, lookup);
        if(cycle_mila) {
          return true;
        }
      }
    }

    lookup[node] = false;
    return false;
  }

  bool containsCycle() {
    bool *visited = new bool[v];
    bool *lookup = new bool[v];

    for(int i = 0; i<v; i++) {
      visited[i] = false;
      lookup[i] = false;
    }
    helper(0, visited, lookup);
  }
};

int main() {
  graph g(4);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  // g.addEdge(3, 0);

  cout<<g.containsCycle();
}
