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
    l[y].push_back(x);
  }

  void dfs_helper(T src, map <T, bool> &visited) {
    cout<<src<<" ";
    visited[src] = true;

    for(T nbr : l[src]) {
      if(visited[nbr] == false) {
        dfs_helper(nbr, visited);
      }
    }
  }

  void dfs() {
    map <T, bool> visited;

    for(auto p : l) {
      T node = p.first;
      visited[node] = false;
    }
    int cnt = 1;
    for(auto node_pair : l) {
      T node = node_pair.first;
      if(!visited[node]) {
        cout<<"Component "<<cnt<<" -> ";
        dfs_helper(node, visited);
        cout<<endl;
        cnt++;
      }
    }
  }
};

int main() {
  graph<int> g;

  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(2, 3);
  g.addEdge(1, 2);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(6, 7);
  g.addEdge(6, 8);
  g.addEdge(7, 9);
  g.addEdge(6, 9);
  g.addEdge(12, 12);


  g.dfs();

  return 0;
}
