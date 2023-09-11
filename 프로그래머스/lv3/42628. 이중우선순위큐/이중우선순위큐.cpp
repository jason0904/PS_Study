#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;



vector<int> solution(vector<string> operations) {
    deque<int> d;
    vector<int> answer;
    for(auto i : operations) {
        vector<string> v;
        v.push_back(i.substr(0,1));
        v.push_back(i.substr(2));
        if(v[0] == "I") {
            d.push_back(stoi(v[1]));
            sort(d.begin(), d.end());
            }
        else if(v[0] == "D") {
            if(d.empty()) continue;
            if(v[1] == "1") d.pop_back();
            else if(v[1] == "-1") d.pop_front();
        }
    }
    if(d.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(d.back());
        answer.push_back(d.front());
    }
    return answer;
}