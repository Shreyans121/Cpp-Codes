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
  void topological_sort() {
    int *indegree = new int[v];
    queue <int> q;
    for(int i = 0; i<v; i++) {
      indegree[i] = 0;
    }
    for(int i = 0; i<v; i++) {
      for(auto y:l[i]) {
        indegree[y]++;
      }
    }
    for(int i = 0; i<v; i++) {
      if(indegree[i] == 0) {
        q.push(i);
      }
    }
    while(!q.empty()) {
      int node = q.front();
      cout<<node<<" ";
      q.pop();
      for(auto p : l[node]) {
        indegree[p]--;
        if(indegree[p] == 0) {
          q.push(p);
        }
      }
    }
  }

};

int main() {
  graph g(6);

  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(2, 5);
  g.addEdge(3, 5);
  g.addEdge(4, 5);

  g.topological_sort();

  return 0;
}
