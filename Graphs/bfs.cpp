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
  void bfs(T src) {
    map <T, bool> visited;
    queue <int> q;

    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
      T temp = q.front();
      q.pop();
      cout<<temp<<", ";

      for(int itr: l[temp]) {
        if(!visited[itr]) {
          q.push(itr);
          visited[itr] = true;
        }
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

  int k = 0;
  g.bfs(k);

  return 0;
}
