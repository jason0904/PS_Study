#include <bits/stdc++.h>
using namespace std;

pair<int,int> lecture[200001];
priority_queue<int, vector<int>, greater<>> pq;

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        lecture[i] = {x,y};
    }
    pq.push(0);
    sort(lecture, lecture + n);
    for(int i = 0; i < n; i++) {
        int s,e,c = pq.top();
        s = lecture[i].first;
        e = lecture[i].second;
        pq.pop();
        if(s < c) pq.push(c);
        pq.push(e);
    }
    cout << pq.size() << "\n";
}