#include <bits/stdc++.h>
using namespace std;


int t;

int main(void) {
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        long long ans = 0;
        priority_queue<long long, vector<long long>, greater<>> pq;
        for(int i = 0; i < k; i++) {
            long long tmp;
            cin >> tmp;
            pq.push(tmp);
        }
        while (pq.size() != 1) {
            long long tmp = pq.top();
            pq.pop();
            long long tmp2 = pq.top();
            pq.pop();
            ans += tmp + tmp2;
            pq.push(tmp + tmp2);
        }
        cout << ans << "\n";
    }
}