// C++ program to find the Dominant Set of a graph
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
bool box[100000];

vector<int> Dominant(int ver, int edge)
{
	vector<int> S; // set S
	for (int i = 0; i < ver; i++) {
		if (!box[i]) {
			S.push_back(i);
			box[i] = true;
			for (int j = 0; j < (int)g[i].size(); j++) {
				if (!box[g[i][j]]) {
					box[g[i][j]] = true;
					break;
				}
			}
		}
	}
	return S;
}

// Driver function
int main()
{
	int ver, edge, x, y;

	ver = 5; // Enter number of vertices
	edge = 6; // Enter number of Edges
	g.resize(ver);

	// Setting all index value of an array as 0
	memset(box, 0, sizeof(box));

	// Enter all the end-points of all the Edges
	// g[x--].push_back[y--]	 g[y--].push_back[x--]

  int inp[100];
  int ip;
  int n = 0;
  while(cin>>ip) {
    inp[n] = ip;
    n++;
  }
  for(int i = 0; i<n; i++) {
      cout<<inp[i]<<" ";
  }

  int k = inp[n-1];
  int nodeCount = 0;
  int parentNode = 0;

  for(int i = 1; i<n-1;) {
    int jump = inp[i];

    while(inp[i]--) {
      nodeCount++;
      g[parentNode].push_back(nodeCount);
      g[nodeCount].push_back(parentNode);
    }
    parentNode++;
    i += jump+1;
  }
  cout<<endl;

  for(int i = 0; i<=nodeCount; i++) {
    int edge = g[i].size();
    cout<<i<<"-> ";
    for(int j = 0; j<edge; j++) {
        cout<<g[i][j]<<" ";
    }
    cout<<endl;
  }


	vector<int> S = Dominant(ver, edge);
	cout << "The Dominant Set is : { ";
	for (int i = 0; i < (int)S.size(); i++)
		cout << S[i] + 1 << " ";
	cout << "}";
	return 0;
}
