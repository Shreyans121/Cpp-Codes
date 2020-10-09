#include<iostream>
#include<vector>
using namespace std;

class graph {
  int v;
  bool **matrix;
public:
  graph(int v) {
    this->v = v;
    matrix = new bool*[v];
    for (int i = 0; i < v; i++) {
      matrix[i] = new bool[v];
      for (int j = 0; j < v; j++)
        matrix[i][j] = false;
  }
}
  void addEdge(int x, int y) {
    matrix[x][y] = true;
    matrix[y][x] = true;
  }

  void printAdjMatrix() {
    for(int i = 0; i<v; i++) {
      for(int j = 0; j<v; j++) {
        cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
    }
  }
};

int main() {
  graph g(4);

  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(2,3);
  g.addEdge(1,2);

  g.printAdjMatrix();

  return 0;
}
