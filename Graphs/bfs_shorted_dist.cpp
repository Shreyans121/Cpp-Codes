#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
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
    map <T, int> dist;
    queue <int> q;

    for(auto node_pair:l) {
      T node = node_pair.first;
      dist[node] = INT_MAX;
    }
    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
      T temp = q.front();
      q.pop();

      for(int itr: l[temp]) {
        if(dist[itr] == INT_MAX) {
          q.push(itr);
          dist[itr] = dist[temp] + 1;
        }
      }
    }
    for(auto node_pair:l) {
      cout<<node_pair.first<<" -> "<<dist[node_pair.first];
      cout<<endl;
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
