#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
const ll mod = 1e9 + 7;
ll n, m;
vector<string> s;
void dfs(ll r, ll c) {
    ll i, j;
    s[r][c] = 'v';
    ll moves[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for(i = 0; i < 4; i++) {
        ll temp_r = r+moves[i][0], temp_c = c+moves[i][1];
        if(temp_r < n && temp_r >= 0 && temp_c < m && temp_c >= 0 && s[temp_r][temp_c] == '.')
            dfs(temp_r, temp_c);
    }
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        ll i, j, ans = 0;
        cin >> n >> m;
        string temp;
        for(i = 0; i < n; i++)
            cin >> temp, s.pb(temp);
        for(i = 0; i < n; i++)
            if(s[i][0] == '.')
                dfs(i, 0);
        for(i = 0; i < n; i++)
            if(s[i][m-1] == '.')
                dfs(i, m-1);
        for(j = 0; j < m; j++)
            if(s[0][j] == '.')
                dfs(0, j);
        for(j = 0; j < m; j++)
            if(s[n-1][j] == '.')
                dfs(n-1, j);
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                if(s[i][j] == '.')
                    ans++;
        cout << ans << endl;
    }
	return 0;
}
