#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
#define piv pair<int, vector<string>>

int main(int argc, char **argv)
{
    int nop = 0;
    cin >> nop;
    vector<int> teams(3, 0);
    for (int i = 0; i < teams.size(); i++)
        cin >> teams[i];
    vector<piv> ingd;

    for (int i = 0; i < nop; i++)
    {
        int noi = 0;
        cin >> noi;
        vector<string> ans(noi, "");
        ingd.push_back({i, ans});
        for (int j = 0; j < noi; j++)
        {
            cin >> ingd[i].second[j];
        }
    }

    vector<int> pizza_teams(3);
    int no_of_teams_with_pizzas = 0;
    for (int i = 0; i < teams.size(); i++)
    {
        while (teams[i] > 0)
        {
            if (nop > 0)
            {
                nop -= (i + 2);
                teams[i]--;
                pizza_teams[i]++;
                no_of_teams_with_pizzas++;
            }

            else
                break;
        }
    }

    sort(ingd.begin(), ingd.end(), [](piv &a, piv &b) {
        if (a.second.size() > b.second.size())
            return a > b;
    });

    cout << no_of_teams_with_pizzas << endl;
    int k = 0;
    for (int i = 0; i < pizza_teams.size(); i++)
    {
        while (pizza_teams[i] > 0)
        {
            cout << i + 2 << " ";
            int count = 0;
            while(count < i + 2)
            {
                cout << ingd[k].first << " ";
                count++;
                k++;
            }
            cout << endl;
            pizza_teams[i]--;
        }
    }
}
