#include<bits/stdc++.h>
using namespace std;

int AppendSort(vector<int> v){
    int cnt = 0;
    for(int i=1;i<v.size();i++){
        if(v[i] <= v[i-1]){
            while(v[i] <= v[i-1]){
                int number = v[i];
                int add_on = 0;
                while(number <= v[i-1] && add_on<=9){
                    number = v[i]*10+add_on;
                    add_on+=1;
                }
                v[i] = number;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    int casenum = 1;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int ans = AppendSort(v);
        cout<<"Case #"<<casenum++<<": "<<ans<<endl;
    }
    return 0;
}
