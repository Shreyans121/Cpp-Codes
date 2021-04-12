#include<bits/stdc++.h>
using namespace std;

long long maxPts = INT_MIN;
int Calculate(vector<int> &vec, int ptr, long long var1, long long var2)
{
    if (vec.size() == ptr)
    {
        if (var1 == var2)
        {
            maxPts = max(maxPts, var2);
            return 1;
        }
        return 0;
    }

    int val = 0;

    val += Calculate(vec, ptr + 1, var1 + vec[ptr], var2);
    val += Calculate(vec, ptr + 1, var1, var2 * vec[ptr]);

    return val;
}

int main(int argc, char** argv) {
    int t;
    cin >>t;
    int casenum = 1;
    while(t--) {
        vector<int> vec;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int num, k;
            cin >> num >> k;
            while(k--) {
                vec.push_back(num);
            }
        }

        maxPts = INT_MIN;
        Calculate(vec, 0, 0, 1);
        if(maxPts == INT_MIN) {
            maxPts = 0;
        }
        cout << "Case #" << casenum << ": "<< maxPts << endl;
        casenum++;
    }
}
