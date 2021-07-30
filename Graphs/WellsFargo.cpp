#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

void solve(vector<vector<int>> &graph){
    queue<pair<int,string>> que;
    que.push({1,"0"});
    string ans = "0";
    while(que.size()!=0){
        pair<int,string> p = que.front();
        que.pop();
        int count = 0;
        for(auto ch:graph[p.first]){
            que.push({ch,p.second + char(count-'0')});
            ans = ans+p.second + char(count-'0');
            count++;
        }
        cout<<ans;
    }
}

int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n,vector<int>());
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    solve(graph);
    return 0;
}
