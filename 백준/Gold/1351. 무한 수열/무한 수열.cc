#include <bits/stdc++.h>
using namespace std;

long long n;
int p, q;
unordered_map<long long, long long> dp;

long long solve(long long tmp) {
    if(tmp == 0) return 1;
    if(dp[tmp]) return dp[tmp];

    dp[tmp] = solve(tmp/p) + solve(tmp/q);
    return dp[tmp];
}

int main(void) {

    cin >> n >> p >> q;

    cout << solve(n) << "\n";

}