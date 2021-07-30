#include <bits/stdc++.h>
using namespace std;

void removeAnagrams(string arr[], int N)
{
    vector<string> ans;
    unordered_set<string> dict;

    for (int i = 0; i < N; i++) {
        string str = arr[i];
        sort(begin(str), end(str));
 

        if (dict.find(str) == dict.end()) {
            ans.push_back(arr[i]);
            dict.insert(str);
        }
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}

int main()
{
    string arr[]
        = { "geeks", "keegs",
            "code", "doce" };
    int N = 4;

    removeAnagrams(arr, N);

    return 0;
}
