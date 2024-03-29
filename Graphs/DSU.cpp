#include<bits/stdc++.h>
using namespace std;

// Cycle Detection in an undirected graph
// Optimisation -
//  - Path Compression
//  - Union By Rank

class graph {
  int v;
  list<pair<int, int>> l;

public:
  graph(int v) {
    this -> v = v;
  }

  void addEdge(int x, int y) {
    l.push_back({x, y});
  }

  int find(int i, int parent[]) {
    if(parent[i] == -1) {
      return i;
    }
    // Path Compression Optimisation
    // return parent[i] = find(parent[i], parent);
    return find(parent[i], parent);
  }

  void unionSet(int a, int b, int parent[], int rank[]) {
    int s1 = find(a, parent);
    int s2 = find(b, parent);

    if(s1 != s2) {
      if(rank[s1] > rank[s2]) {
        parent[s1] = s2;
        rank[s2] += rank[s1];
      }
      else {
        parent[s2] = s1;
        rank[s1] += rank[s2];
      }
    }
  }

  bool containsCycle() {
    int *parent = new int[v];
    int *rank = new int[v];

    for(int i = 0; i<v; i++) {
      parent[i] = -1;
      rank[i] = 1;
    }
    for(auto p: l) {
      int s1 = find(p.first, parent);
      int s2 = find(p.second, parent);

      if(s1 != s2) {
        unionSet(s1, s2, parent, rank);
      }
      else {
        cout<<"Same Cycle "<<s1<<" "<<s2<<endl;
        return true;
      }
    }
    delete [] parent;
    return false;
  }
};

int main() {
  graph g(4);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 0);

  cout<<g.containsCycle();
}
