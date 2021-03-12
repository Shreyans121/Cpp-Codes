#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int i = 1;
        int cnt = 0;
        while(floor(n/pow(5, i)) != 0) {
            cnt += floor(n/pow(5, i));
            i++;
        }
        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}
