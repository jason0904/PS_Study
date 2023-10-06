#include <bits/stdc++.h>
using namespace std;

int Y, X, D;


int main(void) {
    int n;
    cin >> n;
    string cmd;
    cin >> cmd;
    for(auto i : cmd) {
        if(i == 'U') Y++;
        else if(i == 'R') X++;
        else if(i == 'X') D++;
    }
    int k;
    cin >> k;
    int ans = 0;
    while (k--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        // 0 ~ X
        // 0 ~ Y
        int d = min({x, y, D});
        x -= d, y -= d;
        if (X >= x && Y >= y) ans++;
    }
    cout << ans;
}