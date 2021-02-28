#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n = str.length();
    int k;
    cin>>k;

    while(k) {
        int x, y;
        cin>>x>>y;

        unordered_map <char, int> umap;

        for(int i = x; i<(x+y+1)/2; i++) {
            umap[str[i]]++;
        }
        for(int i = (x+y+1)/2; i<=y; i++) {
            umap[str[i]]--;
        }

        unordered_map<char, int> :: iterator itr;
        int flag = 0;

        for(itr = umap.begin(); itr != umap.end(); itr++) {
            if(itr->second != 0) {
                cout<<"No"<<endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            cout<<"Yes"<<endl;
        }
        k--;
    }
    return 0;
}
