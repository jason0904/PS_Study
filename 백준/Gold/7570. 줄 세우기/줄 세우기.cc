#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000001];
int ans;

int main(void) {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    dp[tmp] = dp[tmp-1] + 1;
    ans = max(ans, dp[tmp]);
  }

  cout << n - ans << "\n";

}