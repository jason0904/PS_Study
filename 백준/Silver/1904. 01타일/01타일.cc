#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
int n;

int main(void) {
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 1000000; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    cin >> n;
    cout << dp[n] << "\n";
    return 0;
}