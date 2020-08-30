#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template <typename T>
class graph {
  map <T, list<T>> l;
public:
  void addEdge(int x, int y) {
    l[x].push_back(y);
    // l[y].push_back(x);
  }

  void dfs_helper(T src, map <T, bool> &visited, list <T> &ordering) {
    visited[src] = true;

    for(T nbr : l[src]) {
      if(visited[nbr] == false) {
        dfs_helper(nbr, visited, ordering);
      }
    }
    ordering.push_front(src);
    return;
  }

  void dfs() {
    map <T, bool> visited;
    list<T> ordering;

    for(auto p : l) {
      T node = p.first;
      visited[node] = false;
    }
    int cnt = 1;
    for(auto node_pair : l) {
      T node = node_pair.first;
      if(!visited[node]) {
        dfs_helper(node, visited, ordering);
        cnt++;
      }
    }
    for(auto temp : ordering) {
      cout<<temp<<" ";
    }
  }
};

int main() {
  graph<int> g;

  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 4);
  g.addEdge(3, 5);
  g.addEdge(4, 5);
  g.addEdge(5, 6);
  g.addEdge(7, 6);


  g.dfs();

  return 0;
}
