#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int ans = 0;


int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int day = 0;
    for(auto i : v) {
        if(i == 0) {
            ans = max(ans, day);
            day = 0;
        }
        else day++;
    }
    ans = max(ans, day);
    cout << ans << "\n";
}