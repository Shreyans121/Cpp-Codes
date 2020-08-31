#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
using namespace std;

class graph {
  list <int> *l;
  int v;
public:
  graph(int v) {
    this -> v = v;
    l = new list<int>[v];
  }
  void addEdge(int x, int y) {
    l[x].push_back(y);
  }

  bool is_tree() {
    bool * visited = new bool[v];
    int *parent = new int[v];
    queue <int> q;

    for(int i = 0; i<v; i++) {
      visited[i] = false;
      parent[i] = i;
    }
    int src = 0;

    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
      int node = q.front();
      q.pop();
      for(auto nbr:l[node]) {
        if(visited[nbr] == true && parent[node] != nbr) {
          return false;
        }
        else
        if(!visited[nbr]) {
          visited[nbr] = true;
          parent[node] = nbr;
          q.push(nbr);
        }
      }
    }
    return true;
  }

};

int main() {
  graph g(6);

  g.addEdge(0, 2);
  // g.addEdge(1, 2);
  // g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(2, 5);
  // g.addEdge(3, 5);
  g.addEdge(4, 5);

  cout<<g.is_tree();

  return 0;
}
