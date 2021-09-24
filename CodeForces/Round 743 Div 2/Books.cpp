#include<iostream>
#include<vector>
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

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;

  while(t--) {
    int n;
    cin>>n;

    vector<vector<int>> vec(n+1);
    vector<bool> flag(n+1);
    int cnt = 0;
    bool isPossible = false;
    int ni;
    for(int i = 1; i<=n; i++) {
      cin>>ni;
      if(ni == 0) {
        isPossible = true;
      }

      for(int i = 0; i<ni; i++) {
        int temp;
        cin>>temp;
        vec[i].push_back(temp);
      }
    }

    if(!isPossible) {
      cout<<-1<<endl;
    }
    else {
      while(cnt != n) {
        for(int i = 1; i<=n; i++) {
          for(int j = 1; j<)
        }
      }
    }
  }
  return 0;
}
