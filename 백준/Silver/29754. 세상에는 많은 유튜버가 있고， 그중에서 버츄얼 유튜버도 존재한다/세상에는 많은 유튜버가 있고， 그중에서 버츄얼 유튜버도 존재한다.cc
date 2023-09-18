#include <bits/stdc++.h>
using namespace std;

int n,k;
bool flag = true;

map<string, pair<int,int>> m[53]; //이름, 횟수, 시간;
set<string> s;
vector<string> v;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string name, start_time, end_time;
        int day, time;
        cin >> name >> day >> start_time >> end_time;
        s.insert(name);
        day -= 1;
        time = stoi(end_time.substr(0,2)) * 60 + stoi(end_time.substr(3,2));
        time -= stoi(start_time.substr(0,2)) * 60 + stoi(start_time.substr(3,2));
        m[day/7][name].first += 1;
        m[day/7][name].second += time;
    }
    for(const auto& i : s) {
        bool flag2 = true;
        for(int j = 0; j < k/7; j++) {
            //if(m[j].find(i) == m[j].end()) continue; //이때 주차에는 없다는 거.
            if(!(m[j][i].first >= 5 and m[j][i].second >= 3600)) {
                flag2 = false;
                break;
            }
        }
        if(flag2) {
            flag = false;
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    if(flag) cout << -1 << "\n";
    else {
        for(auto i: v) {
            cout << i << "\n";
        }
    }
}