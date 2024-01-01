#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000001];

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 1000001; i++) {
        for(int j = 1; j < 4; j++) {
            dp[i] = (dp[i] + dp[i-j]) % 1000000009;
        }
    }
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cout << dp[tmp] << "\n";
    }
    
}