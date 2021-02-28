#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

class street {
    public:
    int start = -1;
    int end = -1;
    int time = 0;

    street()
    {
    }

    street(int start, int end, int time)
    {
        this->start = start;
        this->end = end;
        this->time = time;
    }
};

class intersec{
public:
    int intersection_no=0;
    int no_of_incoming_street = 0;
    vector<pair<string,int>> streets_for_time;
};

int main(int argc, char** argv)
{
    int dur_of_simulation = 0;
    int no_of_intersections = 0;
    int no_of_streets = 0;
    int no_of_cars = 0;
    int bonus_points = 0;

    cin >> dur_of_simulation >> no_of_intersections >> no_of_streets >> no_of_cars >> bonus_points;
    unordered_map<string, street> street_map;
    vector<pair<int, vector<string>>> indegree(no_of_intersections, {0,vector<string>()});
    vector<queue<int>> intersections(no_of_intersections);

    for(int i = 0; i < no_of_streets; i++)
    {
        string s;
        int start, end, time;
        cin >> start >> end >> s >> time;
        indegree[end].first++;
        indegree[end].second.push_back(s);
        street k = street(start, end, time);
        street_map[s] = k;
    }

    vector<vector<string>> cars;
    for(int i = 0; i < no_of_cars; i++)
    {
        int p = 0;
        cin >> p;
        vector<string> ans(p, "");
        cars.push_back(ans);
        for(int j = 0; j < p; j++){
            cin >> cars[i][j];
            if(j==0){
                intersections[street_map[cars[i][j]].end].push(i);
            }
        }
    }

    cout << no_of_intersections << endl;
    for(int i = 0; i < no_of_intersections; i++)
    {
        cout << i << endl;
        cout << indegree[i].first << endl;
        for(string s:indegree[i].second)
        {
            if(street_map[s].time == 1)
                cout << s << " 2" << endl;
            else
                cout << s << " 1" << endl;
        }
    }

    vector<pair<int,pair<int,int>>> car_start_moving;
    unordered_map<int,intersec> output;
    int total_time = dur_of_simulation;
    while(dur_of_simulation>0){

        for(int i=0;i<no_of_intersections;i++){
            if(!intersections[i].empty()){
                int car = intersections[i].front();
                if(cars[car].size()>1){
                    car_start_moving.push_back(make_pair(car,make_pair(dur_of_simulation,street_map[cars[car][1]].time)));
                }
                if(total_time!=dur_of_simulation){
                    if(output.find(i)==output.end()){
                        intersec intersec_included;
                        intersec_included.intersection_no = i;
                        intersec_included.no_of_incoming_street = 1;
                        intersec_included.streets_for_time.push_back(make_pair(cars[car][0],1));
                        output[i] = intersec_included;
                    }
                    else{
                        intersec temp = output[i];
                        for(int j=0;j<temp.streets_for_time.size();j++){
                            if(temp.streets_for_time[j].first==cars[car][0]){
                                temp.streets_for_time[j].second+=1;
                            }
                            else{
                                temp.no_of_incoming_street +=1;
                                temp.streets_for_time.push_back(make_pair(cars[car][0],1));
                            }
                        }
                    }
                }
                intersections[i].pop();
            }
        }

        for(int i=0;i<car_start_moving.size();i++){
            if(car_start_moving[i].second.first==(dur_of_simulation-car_start_moving[i].second.second-1)){
                cars[car_start_moving[i].first].erase(cars[car_start_moving[i].first].begin());
                intersections[street_map[cars[car_start_moving[i].first][0]].end].push(car_start_moving[i].first);

                car_start_moving.erase(car_start_moving.begin()+i);
            }
        }

        cout<<output.size()<<endl;
        for(auto t:output){
            intersec o = t.second;
            cout<<o.intersection_no<<endl;
            cout<<o.no_of_incoming_street<<endl;
            for(int j=0;j<o.streets_for_time.size();j++){
                cout<<o.streets_for_time[j].first<<" "<<o.streets_for_time[j].second<<endl;
            }
        }
        dur_of_simulation--;
    }
}
