// Min rolls of Dice and
// The shortest path to reach the destination

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
  }
  int bfs(T src, T dest) {
    map <T, int> dist;
    map <T, T> parent;
    queue <int> q;

    for(auto node_pair:l) {
      T node = node_pair.first;
      dist[node] = INT_MAX;
    }
    q.push(src);
    dist[src] = 0;
    parent[src] = src;

    while(!q.empty()) {
      T temp = q.front();
      q.pop();

      for(int itr: l[temp]) {
        if(dist[itr] == INT_MAX) {
          q.push(itr);
          dist[itr] = dist[temp] + 1;
          parent[itr] = temp;
        }
      }
    }
    T temp = dest;
    while(temp != src) {
      cout<<temp<<" <- ";
      temp = parent[temp];
    }
    cout<<src<<endl;

    return dist[dest];
  }
};

int main() {

  int board[50] = {0};

  board[2] = 13;
  board[5] = 2;
  board[9] = 18;
  board[18] = 11;
  board[17] = -13;
  board[20] = -14;
  board[24] = -8;
  board[25] = 10;
  board[32] = -2;
  board[34] = -22;

  graph<int> g;

  for(int i = 0; i<36; i++) {
    for(int dice = 1; dice<=6; dice++) {
      int j = i + dice;
      j += board[j];

      if(j<=36) {
        g.addEdge(i, j);
      }
    }
  }
  g.addEdge(36, 36);

  cout<<g.bfs(0, 36);

  return 0;
}
