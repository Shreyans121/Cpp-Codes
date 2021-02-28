#include<iostream>
#include<list>
using namespace std;

class graph {
  int v;
  list<int> *l;
  int *rank, *parent;
public:
  graph(int v) {
    this->v = v;
    l = new list<int>[v];
    rank = new int[v];
    parent = new int[v];
  }
  void addEdge(int x, int y) {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  int find(int x, int parent) {
    
  }

  void printAdjList() {
    for(int i = 0; i<v; i++) {
      cout<<i<<" => ";
      for(int j : l[i]) {
        cout<<j<<", ";
      }
      cout<<endl;
    }
  }
};

int main() {
  int n, m;
  cin>>n>>m;
  graph g(n);

  for(int i = 0; i<m; i++) {
    int x, y;
    cin>>x>>y;
    g.addEdge(x, y);
  }

  g.printAdjList();

  return 0;
}
